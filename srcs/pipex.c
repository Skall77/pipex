/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <aaudevar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:26:37 by aaudevar          #+#    #+#             */
/*   Updated: 2022/12/30 17:31:03 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc != 5)
		return (error_msg("Wrong numbers of Arguments.\n", 1));
	pipex.infile_fd = open(argv[1], O_RDONLY);
	if (pipex.infile_fd == -1)
		error_msg_exit("Can't open file1 ", 2);
	pipex.outfile_fd = open(argv[argc - 1], O_TRUNC | O_CREAT | O_RDWR, 0666);
	if (pipex.outfile_fd == -1)
		error_file2("Can't open file2 ", pipex.infile_fd, 3);
	pipex.pathname = pathname(envp);
	pipex.split_path = ft_split(pipex.pathname, ':');
	if (pipex.split_path == NULL)
		error_before_pipe("Bad Malloc in Split ", pipex.infile_fd,
			pipex.outfile_fd, 4);
	if (pipe(pipex.pipe_fd) == -1)
	{
		free_split_path(pipex);
		error_before_pipe("Can't open pipe ", pipex.infile_fd, pipex.outfile_fd,
			5);
	}
	make_fork(pipex, argv, envp);
}

void	make_fork(t_pipex pipex, char **argv, char **envp)
{
	pipex.pid1 = fork();
	if (pipex.pid1 == -1)
		error_fork("Can't fork", pipex, 6);
	if (pipex.pid1 == 0)
		first_child(pipex, argv, envp);
	pipex.pid2 = fork();
	if (pipex.pid2 == -1)
		error_command("Error with second fork ", pipex, 10);
	if (pipex.pid2 == 0)
		second_child(pipex, argv, envp);
	close(pipex.pipe_fd[0]);
	close(pipex.pipe_fd[1]);
	waitpid(pipex.pid1, NULL, 0);
	waitpid(pipex.pid2, NULL, 0);
	free_end(pipex);
}

char	*pathname(char **envp)
{
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5);
}

void	free_split_path(t_pipex p)
{
	int	i;

	i = 0;
	if (p.split_path)
	{
		if (p.split_path[i])
		{
			while (p.split_path[i])
			{
				free(p.split_path[i]);
				i++;
			}
		}
		free(p.split_path);
	}
}

void	free_split_cmd(t_pipex p)
{
	int	i;

	i = 0;
	if (p.split_cmd)
	{
		if (p.split_cmd[i])
		{
			while (p.split_cmd[i])
			{
				free(p.split_cmd[i]);
				i++;
			}
		}
		free(p.split_cmd);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <aaudevar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:26:37 by aaudevar          #+#    #+#             */
/*   Updated: 2023/01/01 12:58:56 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc < min_args(argv[1], &pipex))
		return (error_msg("Wrong numbers of Arguments.\n", 1));
	make_infile(argv, &pipex);
	make_outfile(argv[argc - 1], &pipex);
	pipex.cmds_number = argc - 3 - pipex.here_doc;
	pipex.pipes_number = (pipex.cmds_number - 1) * 2;
	pipex.pipe_fd = malloc(sizeof(int) * pipex.pipes_number);
	if (!pipex.pipe_fd)
		error_msg_exit("Error malloc pipe ", 6);
	pipex.pathname = pathname(envp);
	pipex.split_path = ft_split(pipex.pathname, ':');
	if (pipex.split_path == NULL)
		free_pipe("Bad Malloc ", &pipex);
	make_pipes(&pipex);
	pipex.index = -1;
	while (++(pipex.index) < pipex.cmds_number)
		first_child(pipex, argv, envp);
	close_pipes(&pipex);
	waitpid(-1, NULL, 0);
	free_end(&pipex);
}

void	make_pipes(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (i < pipex->cmds_number - 1)
	{
		if (pipe(pipex->pipe_fd + 2 * i) == -1)
		{
			free_end(pipex);
			error_msg_exit("Problem with pipe ", 7);
		}
		i++;
	}
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

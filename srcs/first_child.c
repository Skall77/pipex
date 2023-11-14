/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_child.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <aaudevar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 11:17:02 by aaudevar          #+#    #+#             */
/*   Updated: 2023/01/18 10:12:54 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	first_child(t_pipex pipex, char **argv, char **envp)
{
	if (dup2(pipex.pipe_fd[1], STDOUT_FILENO) == -1)
	{
		close(pipex.pipe_fd[0]);
		error_split("Problem with dup2 ", pipex, 11);
	}
	close(pipex.pipe_fd[0]);
	if (dup2(pipex.infile_fd, STDIN_FILENO) == -1)
		error_split("Problem with dup2 ", pipex, 12);
	pipex.split_cmd = ft_split(argv[2], ' ');
	if (pipex.split_cmd == NULL)
		error_split("Bad Split of argv ", pipex, 7);
	pipex.command = check_command(pipex.split_path, pipex.split_cmd[0]);
	if (!pipex.command)
		error_command("command not found: ", pipex, 8);
	if (execve(pipex.command, pipex.split_cmd, envp) == -1)
		error_command("Error with execve ", pipex, 9);
}

void	error_split(char *msg, t_pipex pipex, int exit_code)
{
	close(pipex.infile_fd);
	close(pipex.outfile_fd);
	close(pipex.pipe_fd[1]);
	free_split_path(pipex);
	error_msg_exit(msg, exit_code);
}

void	error_command(char *msg, t_pipex pipex, int exit_code)
{
	char	*str;

	str = pipex.split_cmd[0];
	close(pipex.infile_fd);
	close(pipex.outfile_fd);
	close(pipex.pipe_fd[1]);
	write(2, msg, ft_strlen(msg));
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	free_split_path(pipex);
	free_split_cmd(pipex);
	free(pipex.command);
	exit(exit_code);
}

char	*check_command(char **paths, char *cmd)
{
	char	*tmp;
	char	*command;
	int		i;

	i = 0;
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		command = ft_strjoin(tmp, cmd);
		if (tmp)
			free(tmp);
		if (command)
		{
			if (access(command, 0) == 0)
				return (command);
		}
		if (command)
			free(command);
		i++;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_child.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <aaudevar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 12:35:35 by aaudevar          #+#    #+#             */
/*   Updated: 2023/01/18 10:12:50 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	second_child(t_pipex pipex, char **argv, char **envp)
{
	if (dup2(pipex.pipe_fd[0], STDIN_FILENO) == -1)
	{
		close(pipex.pipe_fd[1]);
		error_dup("Error witht dup2 ", pipex, 13);
	}
	close(pipex.pipe_fd[1]);
	if (dup2(pipex.outfile_fd, STDOUT_FILENO) == -1)
		error_dup("Error witht dup2 ", pipex, 14);
	pipex.split_cmd = ft_split(argv[3], ' ');
	if (pipex.split_cmd == NULL)
		error_dup("Bad Split of argv", pipex, 15);
	pipex.command = check_command(pipex.split_path, pipex.split_cmd[0]);
	if (!pipex.command)
		error_command_2("command not found : ", pipex, 16);
	if (execve(pipex.command, pipex.split_cmd, envp) == -1)
		error_dup("Error with execve ", pipex, 17);
}

void	error_dup(char *msg, t_pipex pipex, int exit_code)
{
	close(pipex.infile_fd);
	close(pipex.outfile_fd);
	close(pipex.pipe_fd[0]);
	free_split_path(pipex);
	free_split_cmd(pipex);
	if (pipex.command)
		free(pipex.command);
	error_msg_exit(msg, exit_code);
}

void	error_command_2(char *msg, t_pipex pipex, int exit_code)
{
	char	*str;

	str = pipex.split_cmd[0];
	close(pipex.infile_fd);
	close(pipex.outfile_fd);
	close(pipex.pipe_fd[0]);
	write(2, msg, ft_strlen(msg));
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	free_split_path(pipex);
	free_split_cmd(pipex);
	free(pipex.command);
	exit(exit_code);
}

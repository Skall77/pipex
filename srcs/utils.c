/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <aaudevar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:37:07 by aaudevar          #+#    #+#             */
/*   Updated: 2022/12/30 17:34:52 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	error_msg(char *msg, int exit_code)
{
	write(STDERR_FILENO, msg, ft_strlen(msg));
	return (exit_code);
}

void	error_msg_exit(char *msg, int exit_code)
{
	perror(msg);
	exit(exit_code);
}

void	error_file2(char *msg, int fd, int exit_code)
{
	close(fd);
	error_msg_exit(msg, exit_code);
}

void	error_before_pipe(char *msg, int fd1, int fd2, int exit_code)
{
	close(fd2);
	error_file2(msg, fd1, exit_code);
}

void	error_fork(char *msg, t_pipex pipex, int exit_code)
{
	close(pipex.infile_fd);
	close(pipex.outfile_fd);
	close(pipex.pipe_fd[0]);
	close(pipex.pipe_fd[1]);
	free_split_path(pipex);
	error_msg_exit(msg, exit_code);
}

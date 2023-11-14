/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <aaudevar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:26:28 by aaudevar          #+#    #+#             */
/*   Updated: 2023/01/18 10:11:31 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_pipex
{
	pid_t	pid1;
	pid_t	pid2;
	int		pipe_fd[2];
	int		infile_fd;
	int		outfile_fd;
	char	*pathname;
	char	**split_path;
	char	**split_cmd;
	char	*command;
}			t_pipex;

int			error_msg(char *msg, int exit_code);
void		error_msg_exit(char *msg, int exit_code);
void		error_file2(char *msg, int fd, int exit_code);
char		*pathname(char **envp);
void		error_before_pipe(char *msg, int fd1, int fd2, int exit_code);
void		error_fork(char *msg, t_pipex pipex, int exit_code);
void		make_fork(t_pipex pipex, char **argv, char **envp);
void		first_child(t_pipex pipex, char **argv, char **envp);
void		free_split_path(t_pipex p);
void		error_split(char *msg, t_pipex pipex, int exit_code);
char		*check_command(char **paths, char *cmd);
void		free_split_cmd(t_pipex p);
void		second_child(t_pipex pipex, char **argv, char **envp);
void		error_command(char *msg, t_pipex pipex, int exit_code);
void		error_dup(char *msg, t_pipex pipex, int exit_code);
void		free_end(t_pipex pipex);
void		error_command_2(char *msg, t_pipex pipex, int exit_code);

#endif
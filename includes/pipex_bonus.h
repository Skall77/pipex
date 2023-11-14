/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <aaudevar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:26:28 by aaudevar          #+#    #+#             */
/*   Updated: 2023/01/01 12:59:25 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_pipex
{
	pid_t	pid1;
	int		*pipe_fd;
	int		infile_fd;
	int		outfile_fd;
	char	*pathname;
	char	**split_path;
	char	**split_cmd;
	char	*command;
	int		here_doc;
	int		cmds_number;
	int		pipes_number;
	int		index;
}			t_pipex;

int			error_msg(char *msg, int exit_code);
void		error_msg_exit(char *msg, int exit_code);
char		*pathname(char **envp);
void		error_fork(char *msg, t_pipex pipex, int exit_code);
void		make_pipes(t_pipex *pipex);
void		first_child(t_pipex p, char **argv, char **envp);
void		free_split_path(t_pipex p);
char		*check_command(char **paths, char *cmd);
void		free_split_cmd(t_pipex p);
void		error_pipe(char *msg, t_pipex *pipex, int exit_code);
void		free_end(t_pipex *pipex);
int			min_args(char *str, t_pipex *pipex);
void		make_infile(char **argv, t_pipex *pipex);
void		make_here_doc(char *str, t_pipex *pipex);
void		free_pipe(char *msg, t_pipex *pipex);
void		double_dup2(int in, int out, t_pipex *pipex);
void		close_pipes(t_pipex *pipex);
void		error_commands(t_pipex *pipex);
void		make_outfile(char *str, t_pipex *pipex);
void		error_infile_fd(int exitcode);
void		open_heredoc(int fd, t_pipex *pipex);
#endif
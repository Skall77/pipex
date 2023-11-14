/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_child_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <aaudevar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 11:17:02 by aaudevar          #+#    #+#             */
/*   Updated: 2023/01/01 12:59:48 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	first_child(t_pipex p, char **argv, char **envp)
{
	p.pid1 = fork();
	if (p.pid1 == -1)
	{
		write(2, "Error fork ", 11);
		return ;
	}
	if (p.pid1 == 0)
	{
		if (p.index == 0)
			double_dup2(p.infile_fd, p.pipe_fd[1], &p);
		else if (p.index == p.cmds_number - 1)
			double_dup2(p.pipe_fd[2 * p.index - 2], p.outfile_fd, &p);
		else
			double_dup2(p.pipe_fd[2 * p.index - 2], p.pipe_fd[2 * p.index + 1],
				&p);
		close_pipes(&p);
		p.split_cmd = ft_split(argv[2 + p.here_doc + p.index], ' ');
		if (!p.split_cmd)
			error_msg_exit("Problem with split ", 9);
		p.command = check_command(p.split_path, p.split_cmd[0]);
		if (!p.command)
			error_commands(&p);
		if (execve(p.command, p.split_cmd, envp) == -1)
			error_commands(&p);
	}
}

void	double_dup2(int in, int out, t_pipex *pipex)
{
	if (dup2(in, 0) == -1)
		error_pipe("Bad dup2 ", pipex, 10);
	if (dup2(out, 1) == -1)
		error_pipe("Bad dup2 ", pipex, 10);
}

void	close_pipes(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (i < pipex->pipes_number)
	{
		close(pipex->pipe_fd[i]);
		i++;
	}
}

void	error_pipe(char *msg, t_pipex *pipex, int exit_code)
{
	close(pipex->infile_fd);
	close(pipex->outfile_fd);
	close_pipes(pipex);
	error_msg_exit(msg, exit_code);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <aaudevar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 12:55:38 by aaudevar          #+#    #+#             */
/*   Updated: 2023/01/18 09:51:10 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	free_end(t_pipex *pipex)
{
	int	i;

	i = 0;
	close(pipex->infile_fd);
	close(pipex->outfile_fd);
	if (pipex->here_doc)
		unlink(".heredoc");
	if (pipex->pipe_fd)
		free(pipex->pipe_fd);
	while (pipex->split_path[i])
	{
		free(pipex->split_path[i]);
		i++;
	}
	free(pipex->split_path);
}

void	free_pipe(char *msg, t_pipex *pipex)
{
	close(pipex->infile_fd);
	close(pipex->outfile_fd);
	if (pipex->here_doc)
		unlink(".heredoc");
	if (pipex->pipe_fd)
		free(pipex->pipe_fd);
	error_msg_exit(msg, 7);
}

void	error_commands(t_pipex *pipex)
{
	int		i;
	char	*str;
	char	c;

	c = '\n';
	str = pipex->split_cmd[0];
	write(2, "command not found : ", 20);
	write(2, str, ft_strlen(str));
	write(2, &c, 1);
	close(pipex->infile_fd);
	close(pipex->outfile_fd);
	i = -1;
	while (pipex->split_cmd[++i])
		free(pipex->split_cmd[i]);
	i = -1;
	while (pipex->split_path[++i])
		free(pipex->split_path[i]);
	free(pipex->split_path);
	free(pipex->pipe_fd);
	free(pipex->split_cmd);
	free(pipex->command);
	exit(10);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <aaudevar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 11:12:35 by aaudevar          #+#    #+#             */
/*   Updated: 2023/01/18 09:45:02 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

int	min_args(char *str, t_pipex *pipex)
{
	if (str && !ft_strncmp("here_doc", str, 9))
	{
		pipex->here_doc = 1;
		return (6);
	}
	else
	{
		pipex->here_doc = 0;
		return (5);
	}
}

void	make_infile(char **argv, t_pipex *pipex)
{
	if (!ft_strncmp("here_doc", argv[1], 9))
		make_here_doc(argv[2], pipex);
	else
	{
		pipex->infile_fd = open(argv[1], O_RDONLY);
		if (pipex->infile_fd == -1)
			error_msg_exit("Can't open file1 ", 5);
	}
}

void	make_here_doc(char *str, t_pipex *pipex)
{
	int		fd;
	char	*line;
	int		read_return;

	line = malloc(sizeof(char) * 9999);
	fd = open(".heredoc", O_TRUNC | O_CREAT | O_WRONLY, 0666);
	if (fd == -1)
		error_msg_exit("Can't open here_doc ", 2);
	while (1)
	{
		write(1, "pipe heredoc> ", 14);
		read_return = read(0, line, 9999);
		if (read_return == -1)
			error_msg_exit("Can't read ", 3);
		line[read_return] = '\0';
		if (!ft_strncmp(str, line, ft_strlen(str)))
			break ;
		write(fd, line, ft_strlen(line));
		free(line);
		line = malloc(sizeof(char) * 9999);
	}
	free(line);
	close(fd);
	open_heredoc(fd, pipex);
}

void	open_heredoc(int fd, t_pipex *pipex)
{
	close(fd);
	pipex->infile_fd = open(".heredoc", O_RDONLY);
	if (pipex->infile_fd == -1)
		error_infile_fd(4);
}

void	make_outfile(char *str, t_pipex *pipex)
{
	if (pipex->here_doc == 1)
		pipex->outfile_fd = open(str, O_APPEND | O_CREAT | O_WRONLY, 0666);
	else
		pipex->outfile_fd = open(str, O_TRUNC | O_CREAT | O_RDWR, 0666);
	if (pipex->outfile_fd == -1)
		error_msg_exit("Can't open file2 ", 5);
}

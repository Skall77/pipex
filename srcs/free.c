/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <aaudevar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 12:55:38 by aaudevar          #+#    #+#             */
/*   Updated: 2022/12/30 17:34:19 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	free_end(t_pipex pipex)
{
	int	i;

	i = 0;
	close(pipex.infile_fd);
	close(pipex.outfile_fd);
	while (pipex.split_path[i])
	{
		free(pipex.split_path[i]);
		i++;
	}
	free(pipex.split_path);
}

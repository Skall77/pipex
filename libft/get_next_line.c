/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:10:59 by aaudevar          #+#    #+#             */
/*   Updated: 2022/11/11 14:10:59 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

char	*get_next_line(int fd)
{
	char		*next_line;
	static char	*reserve[9999];

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	reserve[fd] = get_buffer_in_reserve(fd, reserve[fd]);
	if (!reserve[fd])
		return (NULL);
	next_line = get_line_from_reserve(reserve[fd]);
	reserve[fd] = remove_line_from_reserve(reserve[fd]);
	return (next_line);
}

char	*get_buffer_in_reserve(int fd, char *reserve)
{
	char	*buffer;
	int		read_return;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	read_return = 1;
	while (!ft_strchr1(reserve, '\n') && read_return)
	{
		read_return = read(fd, buffer, BUFFER_SIZE);
		if (read_return == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[read_return] = '\0';
		reserve = ft_join_reserve_buffer(reserve, buffer);
		if (!reserve)
		{
			free(buffer);
			return (NULL);
		}
	}
	free (buffer);
	return (reserve);
}

char	*ft_join_reserve_buffer(char *reserve, char *buffer)
{
	size_t	i;
	size_t	j;
	char	*new_reserve;

	if (!reserve)
	{
		reserve = malloc(1);
		if (!reserve)
			return (NULL);
		reserve[0] = '\0';
	}
	new_reserve = malloc(ft_strlen(reserve) + ft_strlen(buffer) + 1);
	if (!new_reserve)
		return (NULL);
	i = -1;
	j = 0;
	if (reserve)
		while (reserve[++i])
			new_reserve[i] = reserve[i];
	while (buffer[j])
		new_reserve[i++] = buffer[j++];
	new_reserve[ft_strlen(reserve) + ft_strlen(buffer)] = '\0';
	free (reserve);
	return (new_reserve);
}

char	*get_line_from_reserve(char *reserve)
{
	int		i;
	char	*line;

	i = 0;
	if (!reserve[i])
		return (NULL);
	while (reserve[i] && reserve[i] != '\n')
		i++;
	line = malloc (i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (reserve[i] && reserve[i] != '\n')
	{
		line[i] = reserve[i];
		i++;
	}
	if (reserve[i] == '\n')
	{
		line[i] = reserve[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*remove_line_from_reserve(char *reserve)
{
	int		i;
	int		j;
	char	*new_reserve;

	i = 0;
	while (reserve[i] && reserve[i] != '\n')
		i++;
	if (!reserve[i])
	{
		free(reserve);
		return (NULL);
	}
	new_reserve = malloc (ft_strlen(reserve) - i + 1);
	if (!new_reserve)
	{
		free(reserve);
		return (NULL);
	}	
	i++;
	j = 0;
	while (reserve[i])
		new_reserve[j++] = reserve[i++];
	new_reserve[j] = '\0';
	free(reserve);
	return (new_reserve);
}

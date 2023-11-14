/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:57:24 by aaudevar          #+#    #+#             */
/*   Updated: 2022/11/14 10:57:28 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include "libft.h"
# include "ft_printf.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# 	endif

char	*get_next_line(int fd);
char	*get_buffer_in_reserve(int fd, char *reserve);
char	*ft_strchr1(char *s, int c);
char	*ft_join_reserve_buffer(char *reserve, char *buffer);
char	*get_line_from_reserve(char *reserve);
char	*remove_line_from_reserve(char *reserve);

#	endif

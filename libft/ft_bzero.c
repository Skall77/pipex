/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:55:30 by aaudevar          #+#    #+#             */
/*   Updated: 2022/11/10 12:22:50 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*cpy;

	if (!s)
		return ;
	cpy = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		cpy[i] = '\0';
		i++;
	}
}

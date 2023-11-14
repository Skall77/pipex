/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:17:31 by aaudevar          #+#    #+#             */
/*   Updated: 2022/11/15 19:37:00 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ret;
	size_t	i;

	i = 0;
	if (size && nmemb > SIZE_MAX / size)
		return (NULL);
	ret = malloc (nmemb * size);
	if (!ret)
		return (NULL);
	while (i < nmemb * size)
	{
		((unsigned char *)ret)[i] = 0;
		i ++;
	}
	return (ret);
}

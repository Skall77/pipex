/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:32:34 by aaudevar          #+#    #+#             */
/*   Updated: 2022/11/09 10:32:36 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	number_size(int n)
{
	int		size;
	long	number;

	number = (long)n;
	size = 0;
	if (number <= 0)
	{
		number = number * -1;
		size++;
	}
	while (number > 0)
	{
		size++;
		number = number / 10;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char			*str;
	int				len;
	unsigned int	number;

	len = number_size(n);
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	str[len--] = '\0';
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		number = n * -1;
		str[0] = '-';
	}
	else
		number = n;
	while (number > 0)
	{
		str[len--] = number % 10 + '0';
		number = number / 10;
	}
	return (str);
}

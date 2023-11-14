/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:05:05 by aaudevar          #+#    #+#             */
/*   Updated: 2022/11/22 10:19:15 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
}

int	ft_put_count_number(int n)
{
	int		size;
	long	nb;

	nb = n;
	if (nb < 0)
	{
		ft_putchar('-');
		nb = nb * -1;
	}
	if (nb < 10)
	{
		ft_putchar('0' + nb);
		return (1);
	}
	size = ft_put_count_number(nb / 10);
	ft_putchar('0' + nb % 10);
	return (1 + size);
}

int	ft_put_count_unsigned(unsigned int n)
{
	long	nb;
	int		size;

	nb = n;
	if (nb < 0)
		nb = nb * -1;
	if (nb < 10)
	{
		ft_putchar('0' + nb);
		return (1);
	}
	size = ft_put_count_unsigned(nb / 10);
	ft_putchar('0' + nb % 10);
	return (1 + size);
}

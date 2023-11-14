/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexadecimals_functions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 16:52:37 by aaudevar          #+#    #+#             */
/*   Updated: 2022/11/20 16:52:37 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base(unsigned int nbr, char *base, t_data *data)
{
	unsigned int	i;

	i = 0;
	while (base[i])
		i++;
	if (nbr < i)
	{
		ft_putchar(base[nbr]);
		(data->size)++;
	}
	if (nbr >= i)
	{
		ft_putnbr_base(nbr / i, base, data);
		ft_putnbr_base(nbr % i, base, data);
	}
}

void	ft_get_hex(unsigned long long nb, t_data *data)
{
	char	*base;

	base = "0123456789abcdef";
	if (nb >= 16)
	{
		ft_get_hex(nb / 16, data);
		ft_get_hex(nb % 16, data);
	}
	else
	{
		ft_putchar(base[nb]);
		(data->size)++;
	}		
}

void	get_adress(unsigned long long nb, t_data *data)
{
	ft_putchar('0');
	ft_putchar('x');
	data->size = data->size + 2;
	ft_get_hex(nb, data);
}

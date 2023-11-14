/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:47:58 by aaudevar          #+#    #+#             */
/*   Updated: 2022/11/22 10:18:49 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conversion_decimal(t_data *data)
{
	int	n;

	n = va_arg(data->ap, int);
	if (n < 0)
		data->size = data->size + 1;
	data->size = data->size + ft_put_count_number(n);
}

void	conversion_char(t_data *data)
{
	char	c;

	c = va_arg(data->ap, int);
	(data->size)++;
	ft_putchar(c);
}

void	conversion_string(t_data *data)
{
	char	*s;

	s = va_arg(data->ap, char *);
	if (s == NULL)
	{
		ft_putstr("(null)");
		data->size = data->size + 6;
		return ;
	}
	ft_putstr(s);
	data->size = data->size + ft_strlen(s);
}

void	conversion_unsigned(t_data *data)
{
	unsigned int	n;

	n = va_arg(data->ap, unsigned int);
	data->size = data->size + ft_put_count_unsigned(n);
}

void	conversion_hexa_lower(t_data *data)
{
	unsigned int	n;

	n = va_arg(data->ap, unsigned int);
	ft_putnbr_base(n, "0123456789abcdef", data);
}

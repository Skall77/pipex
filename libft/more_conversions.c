/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_conversions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 17:23:37 by aaudevar          #+#    #+#             */
/*   Updated: 2022/11/20 17:23:37 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conversion_hexa_upper(t_data *data)
{
	unsigned int	n;

	n = va_arg(data->ap, unsigned int);
	ft_putnbr_base(n, "0123456789ABCDEF", data);
}

void	conversion_adress(t_data *data)
{
	void	*ptr;

	ptr = va_arg(data->ap, void *);
	if (ptr == NULL)
	{
		ft_putstr("(nil)");
		data->size = data->size + 5;
		return ;
	}
	get_adress((unsigned long long)ptr, data);
}

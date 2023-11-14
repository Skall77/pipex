/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:02:41 by aaudevar          #+#    #+#             */
/*   Updated: 2022/11/22 10:21:50 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	t_data	*data;
	int		size;

	data = malloc(sizeof(t_data));
	if (!data)
		return (-1);
	if (!format)
	{
		free(data);
		return (-1);
	}
	if (format[0] == '\0')
	{
		free(data);
		return (0);
	}
	va_start(data->ap, format);
	data->size = read_string(format, data);
	va_end(data->ap);
	size = data->size;
	free(data);
	return (size);
}

int	read_string(const char *s, t_data *data)
{
	int	i;

	i = 0;
	data->size = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			if (check_conversion((s + i + 1), data) == 0)
			{
				ft_putchar(s[i]);
				i++;
				data->size = data->size + 1;
			}
			else
				i = i + 2;
		}
		else
		{
			ft_putchar(s[i]);
			i++;
			data->size = data->size + 1;
		}
	}
	return (data->size);
}

int	check_conversion(const char *s, t_data *data)
{
	int	good;

	good = 1;
	if (s[0] == '%')
	{
		ft_putchar(s[0]);
		data->size = data->size + 1;
	}
	else if (s[0] == 'd' || s[0] == 'i')
		conversion_decimal(data);
	else if (s[0] == 'c')
		conversion_char(data);
	else if (s[0] == 's')
		conversion_string(data);
	else if (s[0] == 'u')
		conversion_unsigned(data);
	else if (s[0] == 'x')
		conversion_hexa_lower(data);
	else if (s[0] == 'X')
		conversion_hexa_upper(data);
	else if (s[0] == 'p')
		conversion_adress(data);
	else
		good = 0;
	return (good);
}

/*#include <stdio.h>
#include <limits.h>

int main(void)
{
	//unsigned int n = INT_MAX;
	//char c = 'q';
	//char *s = NULL;
	int size;
	int size2;
	//printf("%d",ft_printf("This %% work ! "));
	//printf("\n");
	//printf("%d",printf("This %% work ! "));
	size = ft_printf("%y\n", INT_MIN);
	size2 = printf("%y\n", INT_MIN);
	//size = ft_printf("%s\n",s);
	//size2 = printf("%s\n",n);
	printf("%d et %d\n", size, size2);
}*/

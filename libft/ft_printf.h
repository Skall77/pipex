/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:03:50 by aaudevar          #+#    #+#             */
/*   Updated: 2022/11/20 18:47:48 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include "ft_printf.h"

typedef struct s_data {
	va_list		ap;
	int			size;
}				t_data;

void	ft_putchar(char c);
int		check_conversion(const char *s, t_data *data);
void	conversion_decimal(t_data *data);
void	conversion_char(t_data *data);
void	conversion_string(t_data *data);
void	conversion_unsigned(t_data *data);
void	conversion_hexa_lower(t_data *data);
void	conversion_hexa_upper(t_data *data);
void	conversion_adress(t_data *data);
void	ft_putstr(char *s);
int		ft_printf(const char *format, ...);
int		read_string(const char *s, t_data *data);
int		check_conversion(const char *s, t_data *data);
int		ft_put_count_number(int n);
int		ft_put_count_unsigned(unsigned int n);
void	ft_putnbr_base(unsigned int nbr, char *base, t_data *data);
void	ft_get_hex(unsigned long long nb, t_data *data);
void	get_adress(unsigned long long nb, t_data *data);

#endif

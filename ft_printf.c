/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohayek <ohayek@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 20:09:02 by ohayek            #+#    #+#             */
/*   Updated: 2023/06/24 20:09:02 by ohayek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchari(char c)
{
	return (write(1, &c, 1)); 
}

static inline
int	ft_format(char c, va_list list)
{
	if (c == 'c')
		return (ft_putchari(va_arg(list, int)));
	else if (c == 's')
		return (ft_putstri(va_arg(list, char *)));
	else if (c == 'p')
		return (ft_putpointer(va_arg(list, void *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbri(va_arg(list, int)));
	else if (c == 'u')
		return (ft_putdec(va_arg(list, unsigned int)));
	else if (c == 'x')
		return (ft_puthex(va_arg(list, unsigned int), "0123456789abcdef"));
	else if (c == 'X')
		return (ft_puthex(va_arg(list, unsigned int), "0123456789ABCDEF"));
	else if (c == '%')
		return (ft_putchari('%'));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	list;
	int	i;
	int	x;

	va_start(list, str);
	i = 0;
	x = 0;
	while (str[i])
	{
	if (str[i] == '%')
		x += ft_format(str[++i], list);
	else
		x += write(1, &str[i], 1);
	i++;
	}
	va_end(list);
	return (x);
}
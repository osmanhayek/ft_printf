/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohayek <ohayek@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 20:07:05 by ohayek            #+#    #+#             */
/*   Updated: 2023/06/24 20:07:05 by ohayek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbri(int nbr)
{
	static char	buffer[16];
	int		i;
	int		x;
	long	num;

	i = 0;
	x = 0;
	num = nbr;
	if (num == 0)
		return (write(1, "0", 1));
	if (num < 0)
	{
		x += write(1, "-", 1);
		num = -num;
	}
	while (num)
	{
		buffer[i++] = num % 10 + '0';
		num /= 10;
	}
	while (i--)
		x += write(1, &buffer[i], 1);
	return (x);
}

int	ft_putstri(char *str)
{
	int i;

	if (!str)
		return (write(1, "(null)", 6));
	i = 0;
	while (str[i])
		i += write(1, &str[i], 1);
	return (i);
}

int	ft_puthex(unsigned int nbr, char *list)
{
	static char	buffer[16];
	int	i;
	int	x;

	if (nbr == 0)
		return (write(1, "0", 1));
	i = 0;
	x = 0;
	while (nbr)
	{
		buffer[i++] = list[nbr % 16];
		nbr /= 16;
	}
	while (i--)
		x += write(1, &buffer[i], 1);
	return (x);
}

int	ft_putdec(unsigned int nbr)
{
	static char	buffer[16];
	int	i;
	int	x;

	if (nbr == 0)
		return (write(1, "0", 1));
	i = 0;
	x = 0;
	while (nbr)
	{
		buffer[i++] = nbr % 10 + '0';
		nbr /= 10;
	}
	while (i--)
		x += write(1, &buffer[i], 1);
	return (x);
}

int ft_putpointer(void *ptr)
{
	unsigned long	ret;
	int				res;

	ret = (unsigned long)ptr;
	res = 0;
	if (ret > 15)
		res += ft_putpointer((void *)(ret / 16));
	res += ft_putchari("0123456789abcdef"[ret % 16]);
	return (res);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohayek <ohayek@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 20:08:56 by ohayek            #+#    #+#             */
/*   Updated: 2023/06/24 20:08:56 by ohayek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	ft_putstri(char *str);
int	ft_putnbri(int nbr);
int	ft_putdec(unsigned int nbr);
int	ft_puthex(unsigned int nbr, char *list);
int	ft_putpointer(void *ptr);
int	ft_putchari(char c);

#endif
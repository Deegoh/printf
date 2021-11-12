/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 16:44:34 by tpinto-m          #+#    #+#             */
/*   Updated: 2021/11/12 10:34:50 by tpinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_u_nbr_nb(unsigned int n, int *count)
{
	if (n < 0)
	{
		n -= UINT_MAX - 1;
		ft_putnbr_nb(n, count);
	}
	else if (n <= 9)
	{
		n += '0';
		ft_putchar_nb(n, count);
	}
	else
	{
		ft_putnbr_nb(n / 10, count);
		ft_putnbr_nb(n % 10, count);
	}
}

void	check_arg(int i, const char *str, va_list ap, int *count)
{
	if (str[i] == 'c')
		ft_putchar_nb(va_arg(ap, int), count);
	else if (str[i] == 's')
		ft_putstr_nb(va_arg(ap, char *), count);
	else if (str[i] == 'p')
		ft_puthex(va_arg(ap, unsigned long), count, str[i], 1);
	else if (str[i] == 'd')
		ft_putnbr_nb(va_arg(ap, int), count);
	else if (str[i] == 'i')
		ft_putnbr_nb(va_arg(ap, int), count);
	else if (str[i] == 'u')
		ft_put_u_nbr_nb(va_arg(ap, unsigned int), count);
	else if (str[i] == 'x')
		ft_puthex(va_arg(ap, unsigned int), count, str[i], 1);
	else if (str[i] == 'X')
		ft_puthex(va_arg(ap, unsigned int), count, str[i], 1);
	else if (str[i] == '%')
		ft_putstr_nb("%", count);
	i++;
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		count;

	if (!str)
		return (0);
	i = 0;
	count = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] != '%')
			ft_putchar_nb(str[i], &count);
		else
			check_arg(++i, str, ap, &count);
		i++;
	}
	va_end(ap);
	return (count);
}
/*
int	main(void)
{
	int count = 0;
	ft_puthex(1, &count, ft_len_nbr(1), 'p');
}
*/

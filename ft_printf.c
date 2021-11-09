/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 16:44:34 by tpinto-m          #+#    #+#             */
/*   Updated: 2021/11/09 17:53:22 by tpinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_arg(int i, const char *str, va_list argptr, int *count)
{
	char	*arg;

	arg = va_arg(argptr, char *);
	if (str[i + 1] == 'c')
		ft_putchar_nb((int)arg, count);
	else if (str[i + 1] == 's')
		ft_putstr_nb((char *)arg, count);
	else if (str[i + 1] == 'p')
	{
		ft_putstr_nb("0x", count);
		ft_puthex((unsigned long)arg, count, ft_count_nbr((unsigned long)arg));
	}
	else if (str[i + 1] == 'd')
		ft_putnbr_nb((int)arg, count);
	else if (str[i + 1] == 'i')
		ft_putnbr_nb((int)arg, count);
	else if (str[i + 1] == 'u')
		ft_putnbr_nb((unsigned int)arg, count);
	/*
	else if (str[i + 1] == 'x')
		//ft_putnbr_nb((long)arg, count);
	else if (str[i + 1] == 'X')
		//ft_putnbr_nb((long)arg, count);
	else if (str[i + 1] == '%')
		//ft_putnbr_nb((long)arg, count);
	*/
	i++;
}

int	ft_printf(const char *str, ...)
{
	va_list	argptr;
	int		i;
	int		count;

	if (!str)
		return (0);
	i = 0;
	count = 0;
	va_start(argptr, str);
	while (str[i])
	{
		if (str[i] != '%')
		{
			ft_putchar_nb(str[i], &count);
		}
		else
		{
			check_arg(i++, str, argptr, &count);
		}
		i++;
	}
	va_end(argptr);
	return (count);
}
/*
int	main(void)
{
	//int		nbr;
	char	str[] = "world";
	unsigned long	mb;
	int count = 0;

	mb = (unsigned long)str;

	printf("\nptr:%p", str);
	//printf("%d", nbr);
	printf("\n");
	printf("ptr:%lu\n", mb);
	//printf("conv hex:%lx", ft_to_hex(140732794841354));
	ft_puthex(140732835801418, &count);
	//count = ft_printf("NULL %c", 'c');
	printf("\ncount:%d\n", count);
}
*/

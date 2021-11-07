/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 16:44:34 by tpinto-m          #+#    #+#             */
/*   Updated: 2021/11/07 19:54:32 by tpinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_arg(int i, const char *str, va_list argptr)
{
	char	*arg;
	int		count;

	count = 0;
	//printf("ca:str:%s\n", str);
	//printf("ca:arg:%c\n", arg);
	//printf("ca:str[i]:%c\n", str[i]);
	if (str[i + 1] == 'c')
	{
		arg = va_arg(argptr, char*);
		count = ft_putchar_nb((char)arg);
	}
	else if (str[i + 1] == 's')
	{
		arg = va_arg(argptr, char*);
		count = ft_putstr_nb(arg);
	}
	i++;
	//str = va_arg(argptr, const char *);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list argptr;
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
			count += ft_putchar_nb(str[i]);
		}
		else
		{
			count += check_arg(i++, str, argptr);
		}
		i++;
		//check i et count pour le test 10
	}
	va_end(argptr);
	return (count);
}

int	main(void)
{
	int		count;
	int		nbr;
	//char	str[] = "world";
	nbr = printf(" NULL %s NULL ", NULL);
	printf("\n%d", nbr);
	printf("\n\n");
	count = ft_printf(" NULL %s NULL ", NULL);
	printf("\n%d\n", count);
}


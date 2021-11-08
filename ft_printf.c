/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 16:44:34 by tpinto-m          #+#    #+#             */
/*   Updated: 2021/11/08 18:57:53 by tpinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_arg(int i, const char *str, va_list argptr, int *count)
{
	char	*arg;

	arg = va_arg(argptr, char*);
	if (str[i + 1] == 'c')
		ft_putchar_nb((int)arg, count);
	else if (str[i + 1] == 's')
		ft_putstr_nb((char *)arg, count);
	//else if (str[i + 1] == 'p')
		//ft_putstr_nb((char *)arg, count);

	i++;
	return ;
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
			ft_putchar_nb(str[i], &count);
		}
		else
		{
			check_arg(i++, str, argptr, &count);
		}
		i++;
	}
	//printf("count:%d\n", count);
	va_end(argptr);
	return (count);
}


int	main(void)
{
	//int		count;
	//int		nbr;
	char	str[] = "world";
	long	mb;

	mb = (long)str;

	printf("ptr:%p", str);
	//printf("%d", nbr);
	printf("\n");
	printf("ptr:%ld\n", mb );
	printf("/16:%ld", mb/16 );
	//count = ft_printf("NULL %c", 'c');
	//printf("%d", count);
}


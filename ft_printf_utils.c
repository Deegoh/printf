/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 16:32:34 by tpinto-m          #+#    #+#             */
/*   Updated: 2021/11/08 18:57:55 by tpinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_nb(char c, int *count)
{
	write(1, &c, 1);
	*count = *count + 1;
	return ;
}

void	ft_putstr_nb(char *str, int *count)
{
	int i;

	i = 0;
	if (str == NULL)
	{
		write(1, &"(null)", 6);
		*count = *count + 6;
		return ;
	}
	while (str[i])
	{
		ft_putchar_nb(str[i++], count);
	}
	return ;
}

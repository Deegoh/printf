/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 16:32:34 by tpinto-m          #+#    #+#             */
/*   Updated: 2021/11/07 19:54:35 by tpinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_nb(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr_nb(char *str)
{
	int i;

	i = 0;
	while (str[i])
		ft_putchar_nb(str[i++]);
	return (i);
}

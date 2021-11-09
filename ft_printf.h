/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 13:52:50 by tpinto-m          #+#    #+#             */
/*   Updated: 2021/11/09 17:53:20 by tpinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
int		ft_count_nbr(unsigned long nbr);
void	ft_putchar_nb(char c, int *count);
void	ft_putstr_nb(char *str, int *count);
void	ft_puthex(unsigned long nb, int *count, int len);
void	ft_putnbr_nb(int nbr, int	*count);
#endif

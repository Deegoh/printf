/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 13:52:50 by tpinto-m          #+#    #+#             */
/*   Updated: 2021/11/12 10:34:48 by tpinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

int		ft_printf(const char *str, ...);
int		ft_len_nbr(unsigned long nbr);
void	ft_putchar_nb(char c, int *count);
void	ft_putstr_nb(char *str, int *count);
void	ft_puthex(unsigned long nb, int *count, int arg, int first);
void	ft_putnbr_nb(int nbr, int	*count);
void	ft_put_u_nbr_nb(unsigned int n, int *count);

#endif

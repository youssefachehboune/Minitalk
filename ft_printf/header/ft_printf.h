/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachehbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 21:49:23 by yachehbo          #+#    #+#             */
/*   Updated: 2021/11/25 23:10:22 by yachehbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include<stdarg.h>
# include<unistd.h>
# include<stdio.h>

int		ft_printf(const char *str, ...);
void	ft_putchar(char c, int *cp);
void	ft_putstr(char *str, int *cp);
void	ft_pointer(unsigned long n, const char *base, int *cp);
void	ft_putnbr(int n, int *cp);
void	ft_putnbr_unsigned(unsigned int n, int *cp);
void	ft_print_hex(unsigned int n, const char *base, int *cp);
void	ft_helper(const char *str, va_list args, int i, int *cp);
#endif

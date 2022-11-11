/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dseo <dseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 19:00:19 by dseo              #+#    #+#             */
/*   Updated: 2022/06/25 19:22:56 by dseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putnbr_len(int nb);
int		ft_putnbr_unsigned_len(unsigned int nb);
int		ft_putnbr_hex(unsigned long nbr, int flag);
int		ft_print_add(va_list ap, char c);
int		ft_printf(const char *args, ...);

#endif
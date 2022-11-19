/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 23:16:29 by gacalaza          #+#    #+#             */
/*   Updated: 2022/11/19 00:31:04 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# define HEX_LOW "0123456789abcdef"
# define HEX_UPPER "0123456789ABCDEF"

# ifdef __linux__
#  define NULLABLE "(nil)"
# else
#  define NULLABLE "0x0"
# endif

int	ft_printf(const char *format, ...);
int	print_message(char c, va_list args);
int	intputchar(int c);
int	intputstr(char *s);
int	putnbr_hex(unsigned long n, char *base);
int	put_ptr(unsigned long n, char *base);
int	intputnbr(int n);
int	unsputnbr(unsigned int n);

#endif

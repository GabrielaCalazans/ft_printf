/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 23:16:29 by gacalaza          #+#    #+#             */
/*   Updated: 2022/11/21 14:45:17 by gacalaza         ###   ########.fr       */
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
int	ft_print_message(char specifier, va_list args);
int	printf_char(int c);
int	printf_str(char *str);
int	printf_nbr(int nbr);
int	printf_unsnbr(unsigned int nbr);
int	printf_hexnbr(unsigned long nbr, char *base);
int	printf_ptr(unsigned long nbr, char *base);

#endif

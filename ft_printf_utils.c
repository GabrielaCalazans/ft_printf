/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 00:12:40 by gacalaza          #+#    #+#             */
/*   Updated: 2022/11/21 14:47:31 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_nbr(int nbr)
{
	int	count_char;

	count_char = 0;
	if (nbr == -2147483648)
	{
		count_char += printf_char('-');
		count_char += printf_char('2');
		nbr = 147483648;
	}
	if (nbr < 0)
	{
		count_char += printf_char('-');
		nbr *= -1;
	}
	if (nbr < 10)
	{
		count_char += printf_char(nbr + 48);
		return (count_char);
	}
	else
	{
		count_char += printf_nbr(nbr / 10);
	}		
	count_char += printf_nbr(nbr % 10);
	return (count_char);
}

int	printf_unsnbr(unsigned int nbr)
{
	int	count_char;

	count_char = 0;
	if (nbr < 10)
	{
		count_char += printf_char(nbr + 48);
		return (count_char);
	}
	else
	{
		count_char += printf_unsnbr(nbr / 10);
	}		
	count_char += printf_unsnbr(nbr % 10);
	return (count_char);
}

int	printf_hexnbr(unsigned long nbr, char *base)
{
	int	count_char;

	count_char = 0;
	if (nbr >= 16)
		count_char += printf_hexnbr(nbr / 16, base);
	count_char += printf_char(base[nbr % 16]);
	return (count_char);
}

int	printf_ptr(unsigned long nbr, char *base)
{
	int	count_char;

	count_char = 0;
	if (!nbr)
	{
		count_char += printf_str(NULLABLE);
		return (count_char);
	}
	count_char += printf_str("0x");
	count_char += printf_hexnbr(nbr, base);
	return (count_char);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 00:12:40 by gacalaza          #+#    #+#             */
/*   Updated: 2022/11/19 00:27:20 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	intputnbr(int n)
{
	int	count_char;

	count_char = 0;
	if (n == -2147483648)
	{
		count_char += intputchar('-');
		count_char += intputchar('2');
		n = 147483648;
	}
	if (n < 0)
	{
		count_char += intputchar('-');
		n *= -1;
	}
	if (n < 10)
	{
		count_char += intputchar(n + 48);
		return (count_char);
	}
	else
	{
		count_char += intputnbr(n / 10);
	}		
	count_char += intputnbr(n % 10);
	return (count_char);
}

int	unsputnbr(unsigned int n)
{
	int	count_char;

	count_char = 0;
	if (n < 10)
	{
		count_char += intputchar(n + 48);
		return (count_char);
	}
	else
	{
		count_char += unsputnbr(n / 10);
	}		
	count_char += unsputnbr(n % 10);
	return (count_char);
}

int	putnbr_hex(unsigned long int n, char *base)
{
	int	count_char;

	count_char = 0;
	if (n >= 16)
		count_char += putnbr_hex(n / 16, base);
	count_char += (int)write(1, &base[n % 16], 1);
	return (count_char);
}

int	put_ptr(unsigned long int n, char *base)
{
	int	count_char;

	count_char = 0;
	if (!n)
	{
		count_char += intputstr(NULLABLE);
		return (count_char);
	}
	count_char += (int)write(1, "0x", 2);
	count_char += putnbr_hex(n, base);
	return (count_char);
}

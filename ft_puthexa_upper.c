/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_upper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oairola <oairola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:08:33 by olwar             #+#    #+#             */
/*   Updated: 2022/02/28 16:30:56 by oairola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	ft_puthex_upper_neg(unsigned int n, int len)
{
/* 	int	len;
	
	len = 0; */
	if (n / 16 != 0)
	{
		len = ft_puthex_upper_neg(n / 16, len);
		len = ft_puthex_upper_neg(n % 16, len);
	}
	else if (n >= 0 && n <= 9)
	{
		ft_putchar(n + '0');
		len++;
	}
	else
	{
		ft_putchar((n - 10) + 'A');
		len++;
	}
	return (len);
}

static int	ft_puthex_upper(int n, int len)
{
	unsigned	num;
/* 	int			len;

	len = 0; */
	if (n < 0)
	{
		num = n;
		len = ft_puthex_upper_neg(num, 0);
		return (len);
	}
	else if (n / 16 != 0)
	{
		len = ft_puthex_upper(n / 16, len);
		len = ft_puthex_upper(n % 16, len);
	}
	else if (n >= 0 && n <= 9)
	{
		ft_putchar(n + '0');
		len++;
	}
	else
	{
		ft_putchar((n - 10) + 'A');
		len++;
	}
	return (len);
}

int	ft_puthexa_upper(va_list args, t_node *head, char *format_part)
{
	t_node		*ptr;
	int			len;

	len = 0;
	(void)format_part;
	ptr = head;
	if (ptr->data == 16) /* hh */
		len += ft_puthex_upper((unsigned char)va_arg(args, unsigned int), 0);
	if (ptr->data == 18) /* ll */
		len += ft_puthex_upper(va_arg(args, unsigned long long int), 0);
	if (ptr->data == 20) /* h */
		len += ft_puthex_upper((short int)va_arg(args, unsigned long int), 0);
	if (ptr->data == 21) /* l */
		len += ft_puthex_upper(va_arg(args, unsigned long int), 0);
		/* minimum_number_of_ints (is smaller then just add 0s) */
	else 
		len += ft_puthex_upper(va_arg(args, int), 0);
	return (len);
}
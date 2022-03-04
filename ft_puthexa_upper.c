/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_upper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oairola <oairola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:08:33 by olwar             #+#    #+#             */
/*   Updated: 2022/03/04 14:24:19 by oairola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	ft_puthex_upper_neg(unsigned long long n, int len)
{
/* 	int	len;
	
	len = 0; */
	if (n / 16 != 0)
	{
		len = ft_puthex_upper_neg(n / 16, len);
		len = ft_puthex_upper_neg(n % 16, len);
	}
	else if (n <= 9)
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

static int	ft_puthex_upper(unsigned long long int n, int len)
{
	unsigned	num;
/* 	int			len;

	len = 0; */
	if (n < 0)
	{
		num = n;
		len += ft_puthex_upper_neg(num, 0);
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
	va_list		args2;

	len = 0;
	va_copy(args2, args);
	(void)format_part;
	ptr = head;
	if (ptr->data == 16 && ptr->next->data == 17) /* hh */
		len += ft_puthex_upper((unsigned char)va_arg(args, unsigned int), 0);
	if (ptr->data == 18 && ptr->next->data == 19) /* ll */
		len += ft_puthex_upper(va_arg(args, unsigned long long int), 0);
	if (ptr->data == 16) /* h */
		len += ft_puthex_upper((short int)va_arg(args, unsigned long int), 0);
	if (ptr->data == 18) /* l */
		len += ft_puthex_upper(va_arg(args, unsigned long int), 0);
		/* minimum_number_of_ints (is smaller then just add 0s) */
	else 
		len += ft_puthex_upper(va_arg(args, long long int), 0);
	if (ft_justify(args2, head, format_part))
		len += ft_putwidth(args2, head, format_part);
	return (len);
}
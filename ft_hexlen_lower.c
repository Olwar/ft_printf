/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexlen_lower.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olli <olli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 13:55:28 by oairola           #+#    #+#             */
/*   Updated: 2022/03/06 18:17:12 by olli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_puthex_lower_neg(unsigned long long n, int len)
{
/* 	int	len;

	len = 0; */
	if (n / 16 != 0)
	{
		len = ft_puthex_lower_neg(n / 16, len);
		len = ft_puthex_lower_neg(n % 16, len);
	}
	else if (n <= 9)
	{
		len++;
	}
	else
	{
		len++;
	}
	return (len);
}

static int	ft_puthex_lower(long long n, int len)
{
	unsigned int	num;

	if (n < 0)
	{
		num = n;
		len += ft_puthex_lower_neg(num, 0);
		return (len);
	}
	else if (n / 16 != 0)
	{
		len = ft_puthex_lower(n / 16, len);
		len = ft_puthex_lower(n % 16, len);
	}
	else if (n >= 0 && n <= 9)
	{
		len++;
	}
	else
	{
		len++;
	}
	return (len);
}

int	hexlen_lower(va_list args, t_node *head, char *format_part)
{
	t_node		*ptr;
	int			len;
	int			min_number;

	min_number = -1;
	len = 0;
	len += ft_lensign(args, head, format_part);
	if (ft_hash(format_part))
		len += 2;
	ptr = head;
	if (ptr->data == 16) /* hh */
		len += ft_puthex_lower((unsigned char)va_arg(args, unsigned int), 0);
	if (ptr->data == 18) /* ll */
		len += ft_puthex_lower(va_arg(args, unsigned long long int), 0);
	if (ptr->data == 20) /* h */
		len += ft_puthex_lower((short int)va_arg(args, unsigned long int), 0);
	if (ptr->data == 21) /* l */
		len += ft_puthex_lower(va_arg(args, unsigned long int), 0);
		/* minimum_number_of_ints (is smaller then just add 0s) */
	else 
		len += ft_puthex_lower(va_arg(args, long long int), 0);
	return (len);
}
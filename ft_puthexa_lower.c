/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_lower.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oairola <oairola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:08:33 by olwar             #+#    #+#             */
/*   Updated: 2022/03/03 11:34:59 by oairola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_puthex_lower_neg(unsigned int n, int len)
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
		ft_putchar(n + '0');
		len++;
	}
	else
	{
		ft_putchar((n - 10) + 'a');
		len++;
	}
	return (len);
}

static int	ft_puthex_lower(int n, int len)
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
		ft_putchar(n + '0');
		len++;
	}
	else
	{
		ft_putchar((n - 10) + 'a');
		len++;
	}
	return (len);
}

int	ft_puthexa_lower(va_list args, t_node *head, char *format_part)
{
	t_node		*ptr;
	int			len;

	len = 0;
	(void)format_part;
	ptr = head;
	if (ptr->data == 16 && ptr->next->data == 17) /* hh */
		len += ft_puthex_lower((unsigned char)va_arg(args, unsigned int), 0);
	else if (ptr->data == 18 && ptr->next->data == 19) /* ll */
		len += ft_puthex_lower((unsigned long long int)va_arg(args, long int), 0);
	else if (ptr->data == 20) /* h */
		len += ft_puthex_lower((short int)va_arg(args, unsigned long int), 0);
	else if (ptr->data == 18) /* l */
		len += ft_puthex_lower(va_arg(args, unsigned long int), 0);
		/* minimum_number_of_ints (is smaller then just add 0s) */
	else 
		len += ft_puthex_lower(va_arg(args, int), 0);
	if (ft_justify(args, head, format_part))
		ft_putwidth(args, head, format_part);
	return (len);
}
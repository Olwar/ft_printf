/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olli <olli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 12:00:16 by olwar             #+#    #+#             */
/*   Updated: 2022/03/06 18:43:30 by olli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putlongnbr(long long n, int len)
{
	if (n < -9223372036854775807)
	{
		write(1, "-9223372036854775808", 20);
		return (len + 20);
	}
	if (n < 0)
	{
		ft_putchar('-');
		len++;
		len = ft_putlongnbr(-n, len);
	}
	else if (n / 10 != 0)
	{
		len = ft_putlongnbr(n / 10, len);
		len = ft_putlongnbr(n % 10, len);
	}
	else
	{
		ft_putchar(n + '0');
		len++;
	}
	return (len);
}

int	ft_putnbr_printf(va_list args, t_node *head, char *format_part)
{
	int			i;
	long int	a;
	t_node		*ptr;
	int			len;
	int			length;
	int			value;
	va_list		args2;

	va_copy(args2, args);
	i = 0;
	length = 0;
	ptr = head;
	length += put_possible_zeros(args, head, format_part);
	length += ft_putsign(args, head, format_part);
	if (ptr->data == 15) /* . */
	{
		value = va_arg(args, int);
		len = ft_intlen(value);
		while (format_part[++i])
			if (format_part[i] == '.')
				while (ft_intlen(ft_atoi(&format_part[i + 1])) > len)
				{
					write(1, "0", 1);
					len++;
					length++;
				}
	}
	if (ptr->data == 16 && ptr->next->data == 17) /* hh */
		length += ft_putlongnbr((signed char)va_arg(args,int), 0);
	else if (ptr->data == 18 && ptr->next->data == 19) /* ll */
		length += ft_putlongnbr(va_arg(args, long long int), 0);
	else if (ptr->data == 16) /* h */
		length += ft_putlongnbr((signed short int)va_arg(args, int), 0);
	else if (ptr->data == 18) /* l */
		length += ft_putlongnbr(va_arg(args, long int), 0);
	else if (ptr->data == 25) 
		length += ft_putlongnbr(va_arg(args, int), 0);
	else
	{
		a = (long int)va_arg(args, int);
		length += ft_putlongnbr(a, 0);
	}
	ptr = ptr->next;
	if (ft_justify(args2, head, format_part))
		length += ft_putwidth(args2, head, format_part);
	return (length);
}
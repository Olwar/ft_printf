/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putoctal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oairola <oairola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:05:16 by olwar             #+#    #+#             */
/*   Updated: 2022/03/04 12:40:42 by oairola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putoct(long long n, int len)
{
/* 	int	len;
	
	len = 0; */
	if (n < 0)
	{
		ft_putchar('-');
		len++;
		len = ft_putoct(-n, len);
	}
	else if (n / 8 != 0)
	{
		len = ft_putoct(n / 8, len);
		len = ft_putoct(n % 8, len);
	}
	else
	{
		ft_putchar(n + '0');
		len++;
	}
	return (len);
}

int	ft_putoctal(va_list args, t_node *head, char *format_part)
{
	int			i;
	t_node		*ptr;
	int			value;
	int			len;
	long int	a;
	int			length;

	i = 0;
	length = 0;
	ptr = head;
	if (ptr->data == 15) /* . */
	{
		value = va_arg(args, int);
		len = ft_intlen(value);
		while (format_part[++i])
			if (format_part[i] == '.')
				while (ft_intlen(ft_atoi(&format_part[i + 1])) > len)
				{
					write(1, "0", 1);
					length++;
					len++;
				}
	}
	if (ptr->data == 16 && ptr->next->data == 17) /* hh */
		length += ft_putoct((unsigned char)va_arg(args, unsigned int), 0);
	else if (ptr->data == 18 && ptr->next->data == 19) /* ll */
		length += ft_putoct(va_arg(args, unsigned long long int), 0);
	else if (ptr->data == 16) /* h */
		length += ft_putoct((short int)va_arg(args, unsigned long int), 0);
	else if (ptr->data == 18) /* l */
	{
		value = va_arg(args, unsigned long int);
		length += ft_putoct(value, 0);
	}
/* 		if (ptr->data == 25) 
		minimum_number_of_ints (if smaller then just add 0s) */ 
	else
	{	
		a = (long long int)va_arg(args, int);
		length += ft_putoct(a , 0);
	}
	if (ft_justify(args, head, format_part))
		len += ft_putwidth(args, head, format_part);
	return (length);
}
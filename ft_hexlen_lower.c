/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lengthhex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olwar <olwar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 13:55:28 by oairola           #+#    #+#             */
/*   Updated: 2022/03/01 10:29:42 by olwar            ###   ########.fr       */
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
		len++;
	}
	else
	{
		len++;
	}
	return (len);
}

static int	ft_puthex_lower(int n)
{
	unsigned int	num;
	int				len;

	len = 0;
	if (n < 0)
	{
		num = n;
		len += ft_puthex_lower_neg(num, 0);
		return (len);
	}
	else if (n / 16 != 0)
	{
		ft_puthex_lower(n / 16);
		len++;
		ft_puthex_lower(n % 16);
		len++;
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
	int			i;
	t_node		*ptr;
	int			len;
	int			value;

	i = 0;
	ptr = head;
	len = 0;
	while (ptr != NULL)
	{
		if (ptr->data == 25) /* . */
		{
			value = va_arg(args, int);
			len += ft_intlen(value);
			while (format_part[++i])
				if (format_part[i] == '.')
					while (ft_intlen(ft_atoi(&format_part[i + 1])) > len)
					{
						len++;
					}
		}
		if (ptr->data == 16) /* hh */
			len += ft_puthex_lower((unsigned char)va_arg(args, unsigned int));
		else if (ptr->data == 18) /* ll */
			len += ft_puthex_lower(va_arg(args, unsigned long long int));
		else if (ptr->data == 20) /* h */
			len += ft_puthex_lower((short int)va_arg(args, unsigned long int));
		else if (ptr->data == 21) /* l */
			len += ft_puthex_lower(va_arg(args, unsigned long int));
/* 		if (ptr->data == 25) 
			minimum_number_of_ints (if smaller then just add 0s) */ 
		else 
			len += ft_puthex_lower(va_arg(args, int));
		ptr = ptr->next;
	}
	return (len);
}
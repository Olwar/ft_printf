/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oairola <oairola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 12:00:16 by olwar             #+#    #+#             */
/*   Updated: 2022/02/28 15:45:29 by oairola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putlongnbr(long int n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		ft_putchar('-');
		len++;
		ft_putlongnbr(-n);
	}
	else if (n / 10 != 0)
	{
		ft_putlongnbr(n / 10);
		ft_putlongnbr(n % 10);
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

	i = 0;
	length = 0;
	ptr = head;
	while (ptr != NULL)
	{
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
		if (ptr->data == 16) /* hh */
			length += ft_putlongnbr((unsigned char)va_arg(args, unsigned int));
		else if (ptr->data == 18) /* ll */
			length += ft_putlongnbr(va_arg(args, unsigned long long int));
		else if (ptr->data == 20) /* h */
			length += ft_putlongnbr((short int)va_arg(args, unsigned long int));
		else if (ptr->data == 21) /* l */
			length += ft_putlongnbr(va_arg(args, unsigned long int));
 		else if (ptr->data == 25) 
			length += ft_putlongnbr(va_arg(args, unsigned int));
		else
		{
			a = (long int)va_arg(args, int);
			length += ft_putlongnbr(a);
			break;
		}
		ptr = ptr->next;
	}
	return (length);
}
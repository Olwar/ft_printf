/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_octlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olwar <olwar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 10:32:07 by olwar             #+#    #+#             */
/*   Updated: 2022/03/01 10:32:54 by olwar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putoct(long int n, int len)
{
/* 	int	len;
	
	len = 0; */
	if (n < 0)
	{
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
		len++;
	}
	return (len);
}

int	octlen(va_list args, t_node *head, char *format_part)
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
						length++;
						len++;
					}
		}
		if (ptr->data == 16) /* hh */
			length += ft_putoct((unsigned char)va_arg(args, unsigned int), 0);
		else if (ptr->data == 18) /* ll */
			length += ft_putoct(va_arg(args, unsigned long long int), 0);
		else if (ptr->data == 20) /* h */
			length += ft_putoct((short int)va_arg(args, unsigned long int), 0);
		else if (ptr->data == 21) /* l */
			length += ft_putoct(va_arg(args, unsigned long int), 0);
/* 		if (ptr->data == 25) 
			minimum_number_of_ints (if smaller then just add 0s) */ 
		else
		{	
			a = va_arg(args, long int);
			length += ft_putoct(a , 0);
		}
		ptr = ptr->next;
	}
	return (length);
}
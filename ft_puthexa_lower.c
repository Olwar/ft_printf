/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_lower.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oairola <oairola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:08:33 by olwar             #+#    #+#             */
/*   Updated: 2022/02/22 09:03:51 by oairola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_puthex_lower(int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		ft_puthex_lower(-n);
	}
	else if (n / 16 != 0)
	{
		ft_puthex_lower(n / 16);
		ft_puthex_lower(n % 16);
	}
	else if (n >= 0 && n <= 9)
		ft_putchar(n + '0');
	else
		ft_putchar((n - 10) + 'a');
}

void	ft_puthexa_lower(va_list args, t_node *head, char *format_part)
{
	int			i;
	t_node		*ptr;
	int			len;
	int			value;

	i = 0;
	ptr = head;
	while (ptr != NULL)
	{
		if (ptr->data == 25) /* . */
		{
			value = va_arg(args, int);
			len = ft_intlen(value);
			while (format_part[++i])
				if (format_part[i] == '.')
					while (ft_intlen(ft_atoi(&format_part[i + 1])) > len)
					{
						write(1, "0", 1);
						len++;
					}
		}
		if (ptr->data == 16) /* hh */
			ft_puthex_lower((unsigned char)va_arg(args, unsigned int));
		else if (ptr->data == 18) /* ll */
			ft_puthex_lower(va_arg(args, unsigned long long int));
		else if (ptr->data == 20) /* h */
			ft_puthex_lower((short int)va_arg(args, unsigned long int));
		else if (ptr->data == 21) /* l */
			ft_puthex_lower(va_arg(args, unsigned long int));
/* 		if (ptr->data == 25) 
			minimum_number_of_ints (if smaller then just add 0s) */ 
		else 
			ft_puthex_lower(va_arg(args, int));
		ptr = ptr->next;
	}
}
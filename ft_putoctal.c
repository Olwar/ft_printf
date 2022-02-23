/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putoctal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olwar <olwar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:05:16 by olwar             #+#    #+#             */
/*   Updated: 2022/02/23 10:01:40 by olwar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putoct(long int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		ft_putoct(-n);
	}
	else if (n / 8 != 0)
	{
		ft_putoct(n / 8);
		ft_putoct(n % 8);
	}
	else
		ft_putchar(n + '0');
}

void	ft_putoctal(va_list args, t_node *head, char *format_part)
{
	int			i;
	t_node		*ptr;
	int			value;
	int			len;
	long int	a;

	i = 0;
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
					}
		}
		if (ptr->data == 16) /* hh */
			ft_putoct((unsigned char)va_arg(args, unsigned int));
		else if (ptr->data == 18) /* ll */
			ft_putoct(va_arg(args, unsigned long long int));
		else if (ptr->data == 20) /* h */
			ft_putoct((short int)va_arg(args, unsigned long int));
		else if (ptr->data == 21) /* l */
			ft_putoct(va_arg(args, unsigned long int));
/* 		if (ptr->data == 25) 
			minimum_number_of_ints (if smaller then just add 0s) */ 
		else
		{	
			a = va_arg(args, long int);
			ft_putoct(a);
		}
		ptr = ptr->next;
	}
}
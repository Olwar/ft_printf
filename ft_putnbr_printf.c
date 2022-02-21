/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oairola <oairola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 12:00:16 by olwar             #+#    #+#             */
/*   Updated: 2022/02/21 16:10:33 by oairola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putlongnbr(long int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		ft_putlongnbr(-n);
	}
	else if (n / 10 != 0)
	{
		ft_putlongnbr(n / 10);
		ft_putlongnbr(n % 10);
	}
	else
		ft_putchar(n + '0');
}

void	ft_putnbr_printf(va_list args, t_node *head, char *format_part)
{
	int			i;
	long int	a;
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
			ft_putlongnbr((unsigned char)va_arg(args, unsigned int));
		if (ptr->data == 18) /* ll */
			ft_putlongnbr(va_arg(args, unsigned long long int));
		if (ptr->data == 20) /* h */
			ft_putlongnbr((short int)va_arg(args, unsigned long int));
		if (ptr->data == 21) /* l */
			ft_putlongnbr(va_arg(args, unsigned long int));
/* 		if (ptr->data == 25) 
			minimum_number_of_ints (if smaller then just add 0s) */ 
		else
			a = (long int)va_arg(args, int);
			ft_putlongnbr(a);
		ptr = ptr->next;
	}

}
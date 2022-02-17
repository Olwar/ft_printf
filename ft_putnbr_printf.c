/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olwar <olwar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 12:00:16 by olwar             #+#    #+#             */
/*   Updated: 2022/02/17 14:31:19 by olwar            ###   ########.fr       */
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

void	ft_put_d_and_i(va_list args, t_node *head, char *format_part)
{
	long int	a;
	int			i;
	char		*length_flag;
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
						write(1, '0', 1);
						len++;
					}
		}
		if (ptr->data == 16) /* hh */
			ft_putnbr(va_arg(args, unsigned char));
		else if (ptr->data == 18) /* ll */
			ft_putnbr(va_arg(args, unsigned long long int));
		else if (ptr->data == 20) /* h */
			ft_putnbr(va_arg(args, unsigned short int));
		else if (ptr->data == 21) /* l */
			ft_putnbr(va_arg(args, unsigned long int));
/* 		if (ptr->data == 25) 
			minimum_number_of_ints (if smaller then just add 0s) */ 
		else
			a = (long int)va_arg(args, int);
			ft_putlongnbr(a);
	}

}
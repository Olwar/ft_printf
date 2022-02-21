/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfloat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oairola <oairola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:09:06 by olwar             #+#    #+#             */
/*   Updated: 2022/02/21 13:40:06 by oairola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_float(double myfloat, int limiter)
{
	signed long int	decipart;
	signed long int	intpart;

	if (myfloat < 0)
	{
		ft_putchar('-');
		myfloat *= -1;
	}
	intpart = (signed long int)myfloat;
	ft_putnbr(intpart);
	ft_putchar('.');
	myfloat -= intpart;
	if (limiter == 0)
		myfloat *= 1000000;  //upto 6 decimal points
	else
		myfloat *= ((10 * limiter) / 10);
	decipart = (signed long int)(myfloat + 0.5); //+0.5 to round of the value
	ft_printf("%061d", decipart);
}

void	ft_putfloat(va_list args, t_node *head, char *format_part)
{
	int			j;
	t_node		*ptr;

	j = -1;
	ptr = head;
	while (ptr != NULL)
	{
		if (ptr->data == 22)
			ft_float(va_arg(args, double), 0);
		if (ptr->data == 15)
			while (format_part[++j] != '\0')
				if (format_part[j] == '.')
					ft_float(va_arg(args, double), ft_atoi(&format_part[j]));
	}
}
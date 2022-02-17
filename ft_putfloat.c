/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfloat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olwar <olwar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:09:06 by olwar             #+#    #+#             */
/*   Updated: 2022/02/17 10:03:46 by olwar            ###   ########.fr       */
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
	if (limiter == NULL)
		myfloat *= 1000000;  //upto 6 decimal points
	else
		myfloat *= ((10 * limiter) / 10);
	decipart = (signed long int)(myfloat + 0.5); //+0.5 to round of the value
	ft_printf("%061d", decipart);
}

void	ft_putfloat(va_list args, int *info_array)
{
	long int	a;
	int			i;
	char		*length_flag;
	int			j;

	i = -1;
	j = -1;
	while (info_array[++i] != NULL)
	{
		if (info_array[i] == 22)
			ft_float(va_arg(args, double), NULL);
		if (info_array[i] == 15)
			while (format_part[++j] != '\0')
				if format_part[j] == '.'
					ft_float(va_arg(args, double), ft_atoi(&format_part[j]));
	}
}
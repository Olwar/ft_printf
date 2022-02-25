/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfloat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olwar <olwar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:09:06 by olwar             #+#    #+#             */
/*   Updated: 2022/02/25 08:35:34 by olwar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_float(double myfloat, int limiter)
{
	signed long int	decipart;
	signed long int	intpart;
	int				i;

	i = -1;
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
	{
		myfloat *= 1000000;  //upto 6 decimal points
		if (myfloat == 0)
		{
			while (++i < 6)
				ft_putnbr(0);
		}
	}
	else
	{
		myfloat *= ((10 * limiter));
		decipart = (signed long int)(myfloat + 0.5); //+0.5 to round of the value
		ft_putnbr(decipart);
	}
}

void	ft_putfloat(va_list args, t_node *head, char *format_part)
{
	int			j;
	t_node		*ptr;
	int			limiter;

	j = -1;
	ptr = head;
	while (ptr != NULL)
	{
		if (ptr->data == 22)
			ft_float(va_arg(args, double), 0);
		if (ptr->data == 15)
			while (format_part[++j] != '\0')
				if (format_part[j] == '.')
				{
					limiter = ft_atoi(&format_part[j + 1]);
					ft_float(va_arg(args, double), limiter);
					return ;
				}
		ft_float(va_arg(args, double), 0);
		ptr = ptr->next;
	}
}
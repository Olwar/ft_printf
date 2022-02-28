/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfloat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oairola <oairola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:09:06 by olwar             #+#    #+#             */
/*   Updated: 2022/02/28 14:33:40 by oairola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putlongnbr(long long int n, int *length)
{
	if (n < 0)
	{
		ft_putchar('-');
		(*length)++;
		ft_putlongnbr(-n, &length);
	}
	else if (n / 10 != 0)
	{
		ft_putlongnbr(n / 10, &length);
		ft_putlongnbr(n % 10, &length);
	}
	else
	{
		ft_putchar(n + '0');
		(*length)++;
	}
}

void	ft_putlooongnbr(long long int n, int *length)
{
	long long int	a;

	a = (long int)n;
	ft_putlongnbr(a, &length);
}

void	ft_float(double myfloat, int limiter, int *length)
{
	signed long int	decipart;
	signed long int	intpart;
	int				i;

	i = -1;
	if (myfloat < 0)
	{
		ft_putchar('-');
		(*length)++;
		myfloat *= -1;
	}
	intpart = (signed long long int)myfloat;
	(*length) = (*length) + intlen(intpart);
	ft_putnbr(intpart);
	ft_putchar('.');
	(*length)++;
	myfloat -= intpart;
	if (limiter == 0)
	{
		myfloat *= 1000000;  //upto 6 decimal points
		if (myfloat == 0)
		{
			while (++i < 6)
			{
				ft_putnbr(0);
				(*length)++;
			}
		}
	}
	else
	{
		while (limiter != 0)
		{
			myfloat *= 10;
			limiter--;
		}
		decipart = (unsigned long long int)(myfloat + 0.5); //+0.5 to round of the value
		ft_putlooongnbr(decipart, &length);
	}
}

void	ft_putfloat(va_list args, t_node *head, char *format_part, int *length)
{
	int			j;
	t_node		*ptr;
	int			limiter;

	j = -1;
	ptr = head;
	while (ptr != NULL)
	{
		if (ptr->data == 22)
			ft_float(va_arg(args, double), 0, &length);
		if (ptr->data == 15)
			while (format_part[++j] != '\0')
				if (format_part[j] == '.')
				{
					limiter = ft_atoi(&format_part[j + 1]);
					ft_float(va_arg(args, double), limiter, &length);
					return ;
				}
		ft_float(va_arg(args, double), 0, &length);
		ptr = ptr->next;
	}
}
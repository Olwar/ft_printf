/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floatlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olli <olli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 10:34:57 by olwar             #+#    #+#             */
/*   Updated: 2022/03/06 16:15:17 by olli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putlongnbr(long long int n)
{
	int	len;
	
	len = 0;
	if (n < 0)
	{
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
		len++;
	}
	return (len);
}

static int	ft_putlooongnbr(long long int n)
{
	long long int	a;
	int				len;

	a = (long int)n;
	len = ft_putlongnbr(a);
	return (len);
}

static int	ft_float(double myfloat, int limiter)
{
	signed long int	decipart;
	signed long int	intpart;
	int				i;
	int				len;

	i = -1;
	len = 0;
	if (myfloat < 0)
	{
		len++;
		myfloat *= -1;
	}
	intpart = (signed long long int)myfloat;
	len = len + ft_intlen(intpart);
	len++;
	myfloat -= intpart;
	if (limiter == 0)
	{
		myfloat *= 1000000;  //upto 6 decimal points
		if (myfloat == 0)
		{
			while (++i < 6)
			{
				len++;
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
		len = len + ft_putlooongnbr(decipart);
	}
	return (len);
}

int	floatlen(va_list args, t_node *head, char *format_part)
{
	int			j;
	t_node		*ptr;
	int			limiter;
	int			len;

	len = 0;
	j = -1;
	ptr = head;
	len += ft_lensign(args, head, format_part);
	while (ptr != NULL)
	{
		if (ptr->data == 22)
			len = len + ft_float(va_arg(args, double), 0);
		if (ptr->data == 15)
			while (format_part[++j] != '\0')
				if (format_part[j] == '.')
				{
					limiter = ft_atoi(&format_part[j + 1]);
					len = len + ft_float(va_arg(args, double), limiter);
					return (len);
				}
		len = len + ft_float(va_arg(args, double), 0);
		ptr = ptr->next;
	}
	return (len);
}

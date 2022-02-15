/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putoctal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olwar <olwar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:05:16 by olwar             #+#    #+#             */
/*   Updated: 2022/02/15 16:05:45 by olwar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putlongnbr(int n)
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

void	ft_putoctal(va_list args, int *info_array)
{
	long int	a;
	int			i;
	char		*length_flag;
	
	i = 0;
	while (info_array[i] != NULL)
	{
		if (info_array[i] == 16)
			output_as_unsigned_char
		if (info_array[i] == 18)
			output_as_unsigned_long_long_int
		if (info_array[i] == 20)
			output_as__unsigned_short_int
		if (info_array[i] == 21)
			output_as_unsigned_long_int
		if (info_array[i] == 25) /* . */
			/* minimum_number_of_ints (is smaller then just add 0s) */
	}
}
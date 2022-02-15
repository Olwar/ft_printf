/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthash.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olwar <olwar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 11:55:03 by oairola           #+#    #+#             */
/*   Updated: 2022/02/15 13:26:17 by olwar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthash(va_list args, int *info_array)
{
	int	i;
	int	value;

	i = 0;
	while (info_array[i] != NULL)
	{
		if (info_array[i] == 'x' || info_array[i] == 'X' || info_array[i] == 'o')
		{
			value = va_arg(args, int);
			if (value == 0 && info_array[i] == 'o')
			{
				ft_putchar('0');
				ft_putoctal(value);
			}
			else if (value == 0 && info_array[i] == 'o')
				ft_putoctal(value);
			else if (value == 0 && info_array[i] == 'x')
			{
				write(1, "0x", 2);
				put_hexa_lower(value);
			}
			else if (value == 0 && info_array[i] == 'X')
			{
				write(1, "0X", 2);
				put_hexa_uppercase(value);
			}
			else if (info_array[i] == 'X')
				put_hexa_uppercase(value);
			else if (info_array[i] == 'x')
				put_hexa_lower(value);
			else
				ft_error_exit("error");
		}
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthash.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olwar <olwar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 11:55:03 by oairola           #+#    #+#             */
/*   Updated: 2022/02/17 08:49:09 by olwar            ###   ########.fr       */
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
		if (info_array[i] == 27 || info_array[i] == 28 || info_array[i] == 25)
		{
			value = va_arg(args, int);
			if (value == 0 && info_array[i] == 25)
			{
				ft_putchar('0');
				ft_putoctal(args, value);
			}
			else if (value == 0 && info_array[i] == 25)
				ft_putoctal(args, value);
			else if (value == 0 && info_array[i] == 27)
			{
				write(1, "0x", 2);
				put_hexa_lower(value);
			}
			else if (value == 0 && info_array[i] == 28)
			{
				write(1, "0X", 2);
				put_hexa_uppercase(value);
			}
			else if (info_array[i] == 28)
				put_hexa_uppercase(value);
			else if (info_array[i] == 27)
				put_hexa_lower(value);
			else
				ft_error_exit("error");
		}
		i++;
	}
}

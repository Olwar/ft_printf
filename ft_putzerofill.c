/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putzerofill.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olwar <olwar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:29:47 by oairola           #+#    #+#             */
/*   Updated: 2022/02/15 13:27:07 by olwar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putzerofill(va_list args, int *info_array)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (info_array[i] != NULL)
	{
		if (format[j] == 0)
		{
			while (format[j] >= '1' && format[j] <= '9')
			{
				/* number_of_zeros = split into a string and then convert to an int */
				number_of_zeros = ft_atoi(format_part)
			}
			while (k < number_of_zeros)
			{
				ft_putchar('0');
				k++;
			}
		}
		i++;
	}
}
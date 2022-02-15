/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putprecision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olwar <olwar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 11:47:56 by olwar             #+#    #+#             */
/*   Updated: 2022/02/15 11:55:44 by olwar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putprecision(va_list args, int *info_array)
{
	int	i;
	int	value;

	i = 0;
	while (info_array[i] != NULL)
	{
		if (info_array[i] == '.')
			if (info_array[i + 1] == '*')
			{
				value = va_arg(args, int);
			}
		if (info_array[i] == )
	}
}
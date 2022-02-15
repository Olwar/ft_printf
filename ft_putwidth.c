/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwidth.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olwar <olwar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:31:04 by olwar             #+#    #+#             */
/*   Updated: 2022/02/15 13:26:48 by olwar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putwidth(va_list args, int *info_array)
{
	int	i;
	int	value;
	int	j;

	i = 0;
	while (info_array[i] != NULL)
	{
		if (info_array[i] == '*')
		{
			j = -1;
			value = va_arg(args, int);
			while (++j < value)
				write(1, ' ', 1);
			return ;
		}
		else if (info_array[i] >= '1' && info_array[i] <= '9')
		{
			value = ft_atoi(ft_strsub(info_array, i, ft_strlen(&info_array[i])));
			j = -1;
			while (++j < value)
				write(1, ' ', 1);
			return ;
		}
		i++;
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putspace.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olwar <olwar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:06:57 by olwar             #+#    #+#             */
/*   Updated: 2022/02/15 10:17:35 by olwar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putspace(va_list args, int *info_array)
{
	int	i;
	int value;

	i = 0;
	while (info_array[i] != NULL)
	{
		if (info_array[i] == '+')
		{
			ft_putsign(args, info_array);
			return ;
		}
	}
	i = 0;
	value = ft_atoi(va_arg(args, int));
	if (value >= 0)
		write(1, ' ', 1);
}
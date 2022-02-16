/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putsign.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olwar <olwar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:18:13 by olwar             #+#    #+#             */
/*   Updated: 2022/02/15 10:23:01 by olwar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putsign(va_list args, int *info_array)
{
	int	value;

	value = va_arg(args, int);
	if (value > 0)
	{
		write(1, '+', 1);
	}
}
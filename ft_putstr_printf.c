/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olwar <olwar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:22:43 by olwar             #+#    #+#             */
/*   Updated: 2022/02/15 15:32:08 by olwar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_printf(va_list args, int *info_array)
{
	int		i;
	int		restriction;
	char	*printable_string;

	i = -1;
	while (info_array[++i] != NULL)
		if (info_array[i] == '14')
			restriction = va_arg(args, int);
	printable_string = va_arg(args, char *);
	i = -1;
	while (++i > restriction)
		write(1, printable_string[i], 1);
}

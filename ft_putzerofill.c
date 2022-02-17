/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putzerofill.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olwar <olwar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:29:47 by oairola           #+#    #+#             */
/*   Updated: 2022/02/17 14:35:59 by olwar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putzerofill(va_list args, t_node *head, char *format_part)
{
	int			i;
	int			j;
	t_node		*ptr;
	int			number_of_zeros;
	int			k;

	k = 0;
	j = 0;
	i = 0;
	while (ptr != NULL)
	{
		if (format_part[j] == 0)
		{
			while (format_part[j] >= '1' && format_part[j] <= '9')
			{
				/* number_of_zeros = split into a string and then convert to an int */
				number_of_zeros = ft_atoi(format_part);
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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putzerofill.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oairola <oairola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:29:47 by oairola           #+#    #+#             */
/*   Updated: 2022/02/22 15:05:38 by oairola          ###   ########.fr       */
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
	(void)(args);
	ptr = head;
	number_of_zeros = 0;
	if (format_part[j] == '0')
	{
		j++;
		if (format_part[j] >= '1' && format_part[j] <= '9')
		{
			/* number_of_zeros = split into a string and then convert to an int */
			number_of_zeros = ft_atoi(&format_part[j]);
		}
		while (k < (number_of_zeros - 1))
		{
			ft_putchar('0');
			k++;
		}
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_printf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oairola <oairola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 11:00:33 by oairola           #+#    #+#             */
/*   Updated: 2022/02/21 15:17:55 by oairola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_printf(va_list args, t_node *head, char *format_part)
{
	char	c;
	t_node	*ptr;
	int		i;

	ptr = head;
	i = -1;
	while (ptr != NULL)
	{
		if (ptr->data == 29)
		{
			while (format_part[++i])
			{
				if (format_part[i] == 'c')
				{
					c = va_arg(args, int);
					write(1, &c, 1);
				}
			}
		}
		ptr = ptr->next;
	}
}

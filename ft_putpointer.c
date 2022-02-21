/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oairola <oairola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:10:58 by olwar             #+#    #+#             */
/*   Updated: 2022/02/21 15:17:35 by oairola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putpointer(va_list args, t_node *head, char *format_part)
{
	t_node	*ptr;
	int		ptr2;
	int		i;

	ptr = head;
	i = -1;
	while (ptr != NULL)
	{
		if (ptr->data == 31)
		{
			while (format_part[++i])
			{
				if (format_part[i] == 'p')
				{
					ptr2 = va_arg(args, int);
					write(1, &ptr2, 1);
				}
			}
		}
		ptr = ptr->next;
	}
	ptr = va_arg(args, void *);
	/* Find out how get the length of memory address */
	write(1, &ptr, 10);
}
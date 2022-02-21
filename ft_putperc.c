/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putperc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oairola <oairola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:09:58 by olwar             #+#    #+#             */
/*   Updated: 2022/02/21 15:18:57 by oairola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putperc(va_list args, t_node *head, char *format_part)
{
	char	c;
	t_node	*ptr;
	int		i;

	ptr = head;
	i = -1;
	while (ptr != NULL)
	{
		if (ptr->data == 33)
		{
			while (format_part[++i])
			{
				if (format_part[i] == '%')
				{
					c = va_arg(args, int);
					write(1, &c, 1);
				}
			}
		}
		ptr = ptr->next;
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putsign.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oairola <oairola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:18:13 by olwar             #+#    #+#             */
/*   Updated: 2022/02/21 15:19:05 by oairola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putsign(va_list args, t_node *head, char *format_part)
{
	int		value;
	t_node	*ptr;
	int		i;

	ptr = head;
	i = -1;
	while (ptr != NULL)
	{
		if (ptr->data == 5)
		{
			while (format_part[++i])
			{
				if (format_part[i] == '+')
				{
					value = va_arg(args, int);
					if (value > 0)
					{
						write(1, "+", 1);
					}
				}
			}
		}
		ptr = ptr->next;
	}
}
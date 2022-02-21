/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwidth.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oairola <oairola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:31:04 by olwar             #+#    #+#             */
/*   Updated: 2022/02/21 15:19:38 by oairola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putwidth(va_list args, t_node *head, char *format_part)
{
	int		i;
	int		value;
	int		j;
	t_node	*ptr;

	i = 0;
	j = -1;
	ptr = head;
	while (ptr != NULL)
	{
		if (ptr->data == '*')
		{
			j = -1;
			value = va_arg(args, int);
			while (++j < value)
				write(1, " ", 1);
			return ;
		}
		else if (ptr->data >= '1' && ptr->data <= '9')
		{
			while (format_part[++j])
			{
				if (format_part[j] == ptr->data)
				{
					value = ft_atoi(ft_strsub \
					(format_part, j, ft_strlen(&format_part[j])));
				}
			}
			j = -1;
			while (++j < value)
				write(1, " ", 1);
			return ;
		}
		ptr = ptr->next;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwidth.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olwar <olwar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:31:04 by olwar             #+#    #+#             */
/*   Updated: 2022/02/25 14:18:48 by olwar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putwidth(va_list args, t_node *head, char *format_part)
{
	int		value;
	int		j;
	t_node	*ptr;

	j = -1;
	ptr = head;
	value = 0;
	while (ptr != NULL)
	{
		if (ptr->data == 14)
		{
			j = 1;
			value = va_arg(args, int);
			while (++j < value)
				write(1, " ", 1);
			return ;
		}
		else if (ptr->data >= 5 && ptr->data <= 13)
		{
			while (format_part[++j] != '\0')
			{
				if (format_part[j] >= '1' && format_part[j] <= '9')
				{
					value = ft_atoi(ft_strsub \
					(format_part, j, ft_strlen(&format_part[j])));
				}
			}
			j = 1;
			while (++j < value)
				write(1, " ", 1);
			return ;
		}
		ptr = ptr->next;
	}
}

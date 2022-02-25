/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putsign.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olwar <olwar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:18:13 by olwar             #+#    #+#             */
/*   Updated: 2022/02/25 11:45:36 by olwar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putsign(va_list args, t_node *head, char *format_part)
{
	int		value;
	t_node	*ptr;
	int		i;
	va_list args2;

	va_copy(args2, args);
	ptr = head;
	i = -1;
	while (ptr != NULL)
	{
		if (ptr->data == 4)
		{
			while (format_part[++i])
			{
				if (format_part[i] == '+')
				{
					value = va_arg(args, int);
					va_copy(args, args2);
					if (value > 0)
					{
						write(1, "+", 1);
						return ;
					}
				}
			}
		}
		ptr = ptr->next;
	}
}
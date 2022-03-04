/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lenhash.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oairola <oairola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 11:55:03 by oairola           #+#    #+#             */
/*   Updated: 2022/03/04 16:04:37 by oairola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	lenhash(va_list args, t_node *head, char *format_part)
{
	int		i;
	int		value;
	t_node	*ptr;
	int		len;
	va_list	args2;

	(void)format_part;
	va_copy(args2, args);
	len = 0;
	i = 0;
	ptr = head;
	while (ptr != NULL)
	{
		if (ptr->data == 24 || ptr->data == 26 || ptr->data == 27)
		{
			value = va_arg(args2, int);
			if (value != 0 && ptr->data == 24)
			{
				len++;
			}
			else if (value != 0 && ptr->data == 27)
			{
				len += 2;
			}
			else if (value != 0 && ptr->data == 26)
			{
				len += 2;
			}
		}
		ptr = ptr->next;
	}
	return (len);
}

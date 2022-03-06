/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_possible_zeros_len.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olli <olli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 18:45:03 by olli              #+#    #+#             */
/*   Updated: 2022/03/06 18:47:15 by olli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_possible_zeros_len(va_list args, t_node *head, char *format_part)
{
	t_node	*ptr;
	va_list	args2;
	int		length;
	int		len;
	int		value;

	ptr = head;
	while (ptr != NULL)
	{
		if (ptr->data == 15) /* . */
		{
			va_copy(args2, args);
			length = lenfunx(args2, head, format_part);
			value = ft_dot_number(format_part);
			while (length < value)
			{
				len++;
				length++;
			}
			return (len);
		}
		ptr = ptr->next;
	}
	return (0);
}
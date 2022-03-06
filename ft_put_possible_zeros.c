/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_possible_zeros.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olli <olli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 18:43:52 by olli              #+#    #+#             */
/*   Updated: 2022/03/06 19:05:26 by olli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_possible_zeros(va_list args, t_node *head, char *format_part)
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
				write(1, "0", 1);
				len++;
				length++;
			}
			return (len);
		}
		ptr = ptr->next;
	}
	return (0);
}
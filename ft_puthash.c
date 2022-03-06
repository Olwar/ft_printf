/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthash.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olli <olli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 11:55:03 by oairola           #+#    #+#             */
/*   Updated: 2022/03/06 13:56:28 by olli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthash(va_list args, t_node *head, char *format_part)
{
	int		value;
	t_node	*ptr;
	int		len;
	va_list	args2;

	(void)format_part;
	va_copy(args2, args);
	len = 0;
	ptr = head;
	while (ptr != NULL)
	{
		if (ptr->data == 24 || ptr->data == 26 || ptr->data == 27)
		{
			value = va_arg(args2, int);
			if (value != 0 && ptr->data == 24)
			{
				ft_putchar('0');
				len++;
			}
			else if (value != 0 && ptr->data == 27)
			{
				write(1, "0X", 2);
				len += 2;
			}
			else if (value != 0 && ptr->data == 26)
			{
				write(1, "0x", 2);
				len += 2;
			}
		}
		ptr = ptr->next;
	}
	return (len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putspace.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olli <olli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:06:57 by olwar             #+#    #+#             */
/*   Updated: 2022/03/06 14:13:06 by olli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putspace(va_list args, t_node *head, char *format_part)
{
	int		i;
	int		value;
	t_node	*ptr;
	int		len;
	va_list args2;

	i = 0;
	len = 0;
	ptr = head;
	va_copy(args2, args);
	while (ptr != NULL)
	{
		if (ptr->data == 4)
		{
			len += ft_putsign(args, head, format_part);
			return (len);
		}
		if (ptr->data == 3)
		{
			break ;
		}
		i++;
		ptr = ptr->next;
	}
	i = 0;
	value = va_arg(args2, int);
	if (value >= 0)
	{
		write(1, " ", 1);
		len++;
	}
	return (len);
}
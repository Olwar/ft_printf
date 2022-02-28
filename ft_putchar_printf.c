/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_printf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oairola <oairola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 11:00:33 by oairola           #+#    #+#             */
/*   Updated: 2022/02/28 15:48:08 by oairola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_printf(va_list args, t_node *head, char *format_part)
{
	char	c;
	t_node	*ptr;
	int		i;
	int		len;

	ptr = head;
	len = 0;
	i = -1;
	while (ptr != NULL)
	{
		if (ptr->data == 28)
		{
			while (format_part[++i])
			{
				if (format_part[i] == 'c')
				{
					c = va_arg(args, int);
					write(1, &c, 1);
					len++;
				}
			}
		}
		ptr = ptr->next;
	}
	return (len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putperc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oairola <oairola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:09:58 by olwar             #+#    #+#             */
/*   Updated: 2022/02/28 15:46:48 by oairola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putperc(va_list args, t_node *head, char *format_part)
{
	(void)args;
	(void)head;
	(void)format_part;

	ft_putchar('%');
	return (1);
/* 	char	c;
	t_node	*ptr;
	int		i;

	ptr = head;
	i = -1;
	while (ptr != NULL)
	{
		if (ptr->data == 32)
		{
			while (format_part[++i])
			{
				if (format_part[i] == '%')
				{
					c = va_arg(args, int);
					write(1, &c, 1);
				}
			}
		}
		ptr = ptr->next;
	} */
}
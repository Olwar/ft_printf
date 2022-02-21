/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putspace.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oairola <oairola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:06:57 by olwar             #+#    #+#             */
/*   Updated: 2022/02/21 15:19:10 by oairola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putspace(va_list args, t_node *head, char *format_part)
{
	int		i;
	char	*value;
	int		value2;
	t_node	*ptr;

	i = 0;
	ptr = head;
	while (ptr != NULL)
	{
		if (ptr->data == '+')
		{
			ft_putsign(args, head, format_part);
			return ;
		}
		i++;
		ptr = ptr->next;
	}
	i = 0;
	value = va_arg(args, char *);
	value2 = ft_atoi(value);
	if (value2 >= 0)
		write(1, " ", 1);
}
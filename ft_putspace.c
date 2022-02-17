/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putspace.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olwar <olwar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:06:57 by olwar             #+#    #+#             */
/*   Updated: 2022/02/17 14:35:43 by olwar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putspace(va_list args, t_node *head, char *format_part)
{
	int	i;
	int value;
	t_node		*ptr;

	i = 0;
	while (ptr != NULL)
	{
		if (ptr->data == '+')
		{
			ft_putsign(args, head, format_part);
			return ;
		}
		i++;
	}
	i = 0;
	value = ft_atoi(va_arg(args, int));
	if (value >= 0)
		write(1, ' ', 1);
}
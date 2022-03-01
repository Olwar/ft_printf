/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_justify.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olwar <olwar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:59:56 by olwar             #+#    #+#             */
/*   Updated: 2022/03/01 15:06:40 by olwar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_justify(va_list args, t_node *head, char *format_part)
{
	t_node *ptr;

	(void)args;
	(void)format_part;
	ptr = head;
	while (ptr != NULL)
	{
		if (ptr->data == 2)
			return (1);
		ptr = ptr->next;
	}
	return (0);
}

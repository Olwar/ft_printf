/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oairola <oairola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:22:43 by olwar             #+#    #+#             */
/*   Updated: 2022/02/21 16:00:28 by oairola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_printf(va_list args, t_node *head, char *format_part)
{
	int		i;
	int		restriction;
	char	*printable_string;
	t_node	*ptr;

	restriction = 0;
	(void)(format_part);
	i = -1;
	ptr = head;
	while (ptr != NULL)
	{
		if (ptr->data == 14)
			restriction = va_arg(args, int);
		ptr = ptr->next;
	}
	printable_string = va_arg(args, char *);
	i = -1;
	if (restriction != 0)
	{
		while (++i < restriction)
			write(1, &(printable_string[i]), 1);
	}
	else
		write(1, printable_string, ft_strlen(printable_string));
}

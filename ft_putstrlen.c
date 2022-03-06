/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olli <olli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 15:09:54 by oairola           #+#    #+#             */
/*   Updated: 2022/03/06 18:03:16 by olli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oairola <oairola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:22:43 by olwar             #+#    #+#             */
/*   Updated: 2022/03/04 15:00:30 by oairola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstrlen(va_list args, t_node *head, char *format_part)
{
	int		i;
	int		restriction;
	char	*printable_string;
	t_node	*ptr;
	int		len;
	char	*index;

	len = 0;
	restriction = 0;
	(void)(format_part);
	i = -1;
	ptr = head;
	while (ptr != NULL)
	{
		if (ptr->data == 14)
			restriction = va_arg(args, int);
		if (ptr->data == 15) /* . */
		{
			index = ft_strchr(format_part, '.');
			index++;
			restriction = ft_atoi(index);
		}
		ptr = ptr->next;
	}
	printable_string = va_arg(args, char *);
	if (printable_string == NULL)
	{
		return (len + 6);
	}
	if (ft_strcmp(printable_string, "") == 0)
	{
		return (len);
	}
	i = -1;
	if (restriction != 0)
	{
		while (++i < restriction)
		{
			len++;
		}
	}
	else
	{
		len += ft_strlen(printable_string);
	}
	return (len);
}

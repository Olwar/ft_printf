/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwidth.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olli <olli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:31:04 by olwar             #+#    #+#             */
/*   Updated: 2022/03/06 18:36:40 by olli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		lenfunx(va_list args2, t_node *head, char *format_part)
{
	t_node 	*ptr;
	int		len;

	len = 0;
	(void)format_part;
	ptr = head;
	while (ptr != NULL)
	{
		if (ptr->data == 22 || ptr->data == 23)
			return (ft_putnbr_len(args2, head, format_part));
		else if (ptr->data == 26)
			return (len + hexlen_lower(args2, head, format_part));
		else if (ptr->data == 27)
			return (len + hexlen_upper(args2, head, format_part));
		else if (ptr->data == 24 || ptr->data == 25)
			return (len + octlen(args2, head, format_part));
		else if (ptr->data == 28)
			return (1);
		else if (ptr->data == 29)
			return (ft_putstrlen(args2, head, format_part));
		else if (ptr->data == 30)
			return (ptrlen(args2, head, format_part));
		else if (ptr->data == 31)
			return (floatlen(args2, head, format_part));
		else if (ptr->data == 32)
			return (1);
		ptr = ptr->next;
	}
	return (0);
}

/* INTEGROI WIDTH FUNKTIOIHIN */

int	ft_putwidth(va_list args, t_node *head, char *format_part)
{
	int		value;
	int		j;
	t_node	*ptr;
	va_list	args2;
	int		len;
	int		length;

	j = -1;
	ptr = head;
	value = 0;
	len = 0;
	length = 0;
	while (ptr != NULL)
	{
		if (ptr->data == 14) /* * */
		{
			j = 0;
			va_copy(args2, args);
			length = lenfunx(args2, head, format_part);
			value = va_arg(args, int);
			value = value - length;
			while (++j < value)
			{
				if (ft_checkzero(args, head, format_part))
					write(1, "0", 1);
				else
					write(1, " ", 1);
				len++;
			}
			return (len);
		}
		else if (ptr->data >= 5 && ptr->data <= 13)
		{
			va_copy(args2, args);
			length = lenfunx(args2, head, format_part);
			while (format_part[++j] != '\0')
			{
				if (format_part[j] >= '1' && format_part[j] <= '9')
				{
					value = ft_atoi(ft_strsub \
					(format_part, j, ft_strlen(&format_part[j])));
					value = value - length;
					break;
				}
			}
			j = -1;
			if (ft_checkzero(args, head, format_part))
			{
				while (++j < value)
				{
					write(1, "0", 1);
					len++;
				}
			}
			else
			{
				while (++j < value)
				{
					write(1, " ", 1);
					len++;
				}
			}
			return (len);
		}
		ptr = ptr->next;
	}
	return (len);
}

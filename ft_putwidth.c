/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwidth.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olwar <olwar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:31:04 by olwar             #+#    #+#             */
/*   Updated: 2022/03/01 08:55:43 by olwar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		lenfunx(va_list args2, t_node *head, char *format_part)
{
	t_node 	*ptr;
	/* int		len; */

	(void)args2;
	(void)format_part;
	ptr = head;
	return (0);
/* 	while (ptr != NULL)
	{
		if (ptr->data == 22 || ptr->data == 23)
			return (ft_intlen(va_arg(args2, long int)));
		if (ptr->data == 26 || ptr->data == 27)
			return (hexlen(va_arg(args2, long int)));
		if (ptr->data == 24 || ptr->data == 25)
			return (octlen(va_arg(args2, long int)));
		if (ptr->data == 28)
			return (1);
		if (ptr->data == 29)
			return (ft_strlen(va_arg(args2, char *)));
		if (ptr->data == 30)
			return (ptrlen(va_arg(args2, long int)));
		if (ptr->data == 31)
			return (floatlen(va_arg(args2, double)));
	} */
}

/* INTEGROI WIDTH FUNKTIOIHIN */

int	ft_putwidth(va_list args, t_node *head, char *format_part)
{
	int		value;
	int		j;
	t_node	*ptr;
	va_list	args2;
	int		len;

	j = -1;
	ptr = head;
	value = 0;
	len = 0;
	while (ptr != NULL)
	{
		if (ptr->data == 14)
		{
			j = 1;
			value = va_arg(args, int);
			while (++j < value)
			{
				write(1, " ", 1);
				len++;
			}
			return (len);
		}
		else if (ptr->data >= 5 && ptr->data <= 13)
		{
			va_copy(args2, args);
			len = lenfunx(args2, head, format_part);
			while (format_part[++j] != '\0')
			{
				if (format_part[j] >= '1' && format_part[j] <= '9')
				{
					value = ft_atoi(ft_strsub \
					(format_part, j, ft_strlen(&format_part[j])));
					value = value - len;
				}
			}
			j = 1;
			while (++j < value)
			{
				write(1, " ", 1);
				len++;
			}
			return (len);
		}
		ptr = ptr->next;
	}
	return (len);
}

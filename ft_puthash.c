/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthash.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oairola <oairola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 11:55:03 by oairola           #+#    #+#             */
/*   Updated: 2022/02/28 15:27:16 by oairola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthash(va_list args, t_node *head, char *format_part)
{
	int		i;
	int		value;
	t_node	*ptr;
	int		len;

	len = 0;
	i = 0;
	ptr = head;
	while (ptr != NULL)
	{
		if (ptr->data == 27 || ptr->data == 28 || ptr->data == 25)
		{
			value = va_arg(args, int);
			if (value == 0 && ptr->data == 25)
			{
				ft_putchar('0');
				len++;
				ft_putoctal(args, head, format_part);
			}
			else if (value == 0 && ptr->data == 25)
				ft_putoctal(args, head, format_part);
			else if (value == 0 && ptr->data == 27)
			{
				write(1, "0x", 2);
				len += 2;
				ft_puthexa_lower(args, head, format_part);
			}
			else if (value == 0 && ptr->data == 28)
			{
				write(1, "0X", 2);
				len += 2;
				ft_puthexa_upper(args, head, format_part);
			}
			else if (ptr->data == 28)
				ft_puthexa_upper(args, head, format_part);
			else if (ptr->data == 27)
				ft_puthexa_lower(args, head, format_part);
			else
				ft_error_exit("error");
		}
		i++;
	}
	return (len);
}

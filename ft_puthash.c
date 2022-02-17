/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthash.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olwar <olwar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 11:55:03 by oairola           #+#    #+#             */
/*   Updated: 2022/02/17 14:38:29 by olwar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthash(va_list args, t_node *head, char *format_part)
{
	int	i;
	int	value;
	t_node		*ptr;

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
				ft_putoctal(args, head, format_part);
			}
			else if (value == 0 && ptr->data == 25)
				ft_putoctal(args, head, format_part);
			else if (value == 0 && ptr->data == 27)
			{
				write(1, "0x", 2);
				ft_puthexa_lower(args, head, format_part);
			}
			else if (value == 0 && ptr->data == 28)
			{
				write(1, "0X", 2);
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
}

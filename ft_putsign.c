/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putsign.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olli <olli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:18:13 by olwar             #+#    #+#             */
/*   Updated: 2022/03/06 16:14:29 by olli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_lensign(va_list args, t_node *head, char *format_part)
{
	int		value;
	t_node	*ptr;
	int		i;
	va_list args2;
	int		len;

	len = 0;
	va_copy(args2, args);
	ptr = head;
	i = -1;
	while (ptr != NULL)
	{
		if (ptr->data == 4)
		{
			while (format_part[++i])
			{
				if (format_part[i] == '+')
				{
					value = va_arg(args, int);
					va_copy(args, args2);
					if (value > 0)
					{
						len++;
						return (len);
					}
				}
			}
		}
		ptr = ptr->next;
	}
	return (len);
}

int	ft_putsign(va_list args, t_node *head, char *format_part)
{
	int		value;
	t_node	*ptr;
	int		i;
	va_list args2;
	int		len;

	len = 0;
	va_copy(args2, args);
	ptr = head;
	i = -1;
	while (ptr != NULL)
	{
		if (ptr->data == 4)
		{
			while (format_part[++i])
			{
				if (format_part[i] == '+')
				{
					value = va_arg(args, int);
					va_copy(args, args2);
					if (value > 0)
					{
						write(1, "+", 1);
						len++;
						return (len);
					}
				}
			}
		}
		ptr = ptr->next;
	}
	return (len);
}
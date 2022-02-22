/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oairola <oairola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:10:58 by olwar             #+#    #+#             */
/*   Updated: 2022/02/22 09:51:34 by oairola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putaddress(int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		ft_puthex_lower(-n);
	}
	else if (n / 16 != 0)
	{
		ft_puthex_lower(n / 16);
		ft_puthex_lower(n % 16);
	}
	else if (n >= 0 && n <= 9)
		ft_putchar(n + '0');
	else
		ft_putchar((n - 10) + 'a');
}

void	ft_putpointer(va_list args, t_node *head, char *format_part)
{
	void	*ptr;

	(void) head;
	(void) format_part;
	ptr = va_arg(args, void *);
	/* Find out how get the length of memory address */
	ft_putaddress(ptr);
}
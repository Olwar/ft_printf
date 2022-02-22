/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_upper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oairola <oairola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:08:33 by olwar             #+#    #+#             */
/*   Updated: 2022/02/22 09:04:44 by oairola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_puthex_upper(int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		ft_puthex_upper(-n);
	}
	else if (n / 16 != 0)
	{
		ft_puthex_upper(n / 16);
		ft_puthex_upper(n % 16);
	}
	else if (n >= 0 && n <= 9)
		ft_putchar(n + '0');
	else
		ft_putchar((n - 10) + 'A');
}

void	ft_puthexa_upper(va_list args, t_node *head, char *format_part)
{
	int			i;
	t_node		*ptr;

	(void)format_part;
	i = 0;
	ptr = head;
	while (ptr != NULL)
	{
		if (ptr->data == 16) /* hh */
			ft_puthex_upper((unsigned char)va_arg(args, unsigned int));
		if (ptr->data == 18) /* ll */
			ft_puthex_upper(va_arg(args, unsigned long long int));
		if (ptr->data == 20) /* h */
			ft_puthex_upper((short int)va_arg(args, unsigned long int));
		if (ptr->data == 21) /* l */
			ft_puthex_upper(va_arg(args, unsigned long int));
			/* minimum_number_of_ints (is smaller then just add 0s) */
		else 
			ft_puthex_upper(va_arg(args, int));
		ptr = ptr->next;
	}
}
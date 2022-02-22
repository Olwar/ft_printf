/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oairola <oairola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:10:58 by olwar             #+#    #+#             */
/*   Updated: 2022/02/22 16:13:08 by oairola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

char hex_digit(uintptr_t v) {
    if (v >= 0 && v < 10)
        return '0' + v;
    else
        return 'a' + v - 10; // <-- Here
}

void	ft_putpointer(va_list args, t_node *head, char *format_part)
{
	int i;
	uintptr_t	ptr;

	(void) head;
	(void) format_part;
	ptr = va_arg(args, uintptr_t);
    ft_putchar('0'); 
	ft_putchar('x');
	i = 32;
    while (i>=0)
	{
        ft_putchar(hex_digit((ptr >> i) & 0xf));
		i -= 4;
    }
}
/* 
 static void	ft_putaddress(unsigned char n)
{
	if (n < 0)
	{
		ft_putchar('-');
		ft_putaddress(-n);
	}
	else if (n / 16 != 0)
	{
		ft_putaddress(n / 16);
		ft_putaddress(n % 16);
	}
	else if (n >= 0 && n <= 9)
		ft_putchar(n + '0');
	else if (n >= 'a' && n <= 'f')
		ft_putchar(n - '0');
	else
		ft_putchar((n - 10) + 'a');
}

void	ft_putpointer(va_list args, t_node *head, char *format_part)
{
	void			*ptr;
	unsigned char	*ptr2;
	int				i;

	i = -1;
	(void) head;
	(void) format_part;
	ptr = va_arg(args, void *);
	Find out how to get the length of memory address
	ptr2 = (unsigned char)ptr;
	ft_putaddress(ptr2);
	printf("%p", ptr);
} */
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olwar <olwar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 10:33:46 by olwar             #+#    #+#             */
/*   Updated: 2022/03/01 10:59:24 by olwar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char hex_digit(uintptr_t v) {
    if (v < 10)
        return '0' + v;
    else
        return 'a' + v - 10; // <-- Here
}

int	ptrlen(va_list args, t_node *head, char *format_part)
{
	int i;
	uintptr_t	ptr;
	char		c;
	int			flag;
	int			length;

	length = 0;
	flag = 0;
	(void) head;
	(void) format_part;
	ptr = va_arg(args, uintptr_t);
	length += 2;
	i = (sizeof(ptr) << 3) - 4;
    while (i>=0)
	{
        c = hex_digit((ptr >> i) & 0xf);
		if (c != '0' || flag == 1)
		{
			length++;
			flag = 1;
		}
		i -= 4;
    }
	return (length);
}
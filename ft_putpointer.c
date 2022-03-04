/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oairola <oairola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:10:58 by olwar             #+#    #+#             */
/*   Updated: 2022/03/04 10:42:08 by oairola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char hex_digit(uintptr_t v) {
    if (v < 10)
        return '0' + v;
    else
        return 'a' + v - 10; // <-- Here
}

int	ft_putpointer(va_list args, t_node *head, char *format_part)
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
    ft_putchar('0'); 
	ft_putchar('x');
	length += 2;
	if (ptr == 0)
	{
		write(1, "0", 1);
		return (length + 1);
	}
	i = (sizeof(ptr) << 3) - 4;
    while (i>=0)
	{
        c = hex_digit((ptr >> i) & 0xf);
		if (c != '0' || flag == 1)
		{
			ft_putchar(c);
			length++;
			flag = 1;
		}
		i -= 4;
    }
	return (length);
}

/*  static void	ft_putaddress(unsigned char n)
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
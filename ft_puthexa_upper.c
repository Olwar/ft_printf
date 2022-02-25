/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_upper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olwar <olwar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:08:33 by olwar             #+#    #+#             */
/*   Updated: 2022/02/25 15:49:46 by olwar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

unsigned int reverseBits(unsigned int num)
{
    unsigned int  NO_OF_BITS = sizeof(num) * 8;
    unsigned int reverse_num = 0, i, temp;
	int	remainder;
	int	hexadecimalval;
  
    for (i = 0; i < NO_OF_BITS; i++)
    {
        temp = (num & (1 << i));
        if(temp)
            reverse_num |= (1 << ((NO_OF_BITS - 1) - i));
    }
	reverse_num++;
	i = 1;
	while (reverse_num != 0)
    {
        remainder = reverse_num % 10;
        hexadecimalval = hexadecimalval + remainder * i;
        i = i * 2;
        reverse_num = reverse_num / 10;
    }
    return (hexadecimalval);
}

static void	ft_puthex_upper(int n)
{
	if (n < 0)
	{
		n = -n;
		n = reverseBits(n);
		ft_puthex_upper(n);
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
	t_node		*ptr;

	(void)format_part;
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
/* #include <stdio.h>
#include "ft_printf.h"

static void	ft_putblex(int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		ft_puthex(-n);
	}
	else if (n / 16 != 0)
	{
		ft_puthex(n / 16);
		ft_puthex(n % 16);
	}
	else if (n >= 0 && n <= 9)
		ft_putchar(n + '0');
	else
		ft_putchar((n - 10) + 'a');
}

int zain(void)
{
	ft_puthex(4000);
	printf("\n%x\n", 4000);
} */
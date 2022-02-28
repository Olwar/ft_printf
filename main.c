#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"

int main(void)
{
	char	*str = "Ma'am";
	char	*format;
	int		i;
	system("echo Nice to meet you $(whoami)");
	printf("\ntesting string:\n");
	ft_printf("\tHello\n");
	printf("\tHello\n");

	printf("\ntesting another string:\n");
	ft_printf("\tHello %s\n", str);
	printf("\tHello %s\n", str);

 	printf("\ntesting upper-case character\n");
	ft_printf("\tThis... is... %cPARTA!\n", 'S');
	printf("\tThis... is... %cPARTA!\n", 'S'); 

	printf("\ntesting lower-case character\n");
	ft_printf("\tThis... is... %canta! Ho ho ho!\n", 's');
	printf("\tThis... is... %canta! Ho ho ho!\n", 's');

	printf("\ntesting integer\n");
	ft_printf("\tIs this mambo number %d\n", 5);
	printf("\tIs this mambo number %d\n", 5);

	printf("\ntesting negative integer\n");
	ft_printf("\tIs this mambo number %d\n", -5);
	printf("\tIs this mambo number %d\n", -5);

	printf("\ntesting float\n");
	ft_printf("\tSo far I've made %f€ on my programming career\n", 0.00);
	printf("\tSo far I've made %f€ on my programming career\n", 0.00);

	printf("\ntesting hexadecimal\n");
	ft_printf("\tGot an %x on my exam\n", 16);
	printf("\tGot an %x on my exam\n", 16);

	printf("\ntesting BIG hexadecimal\n");
	ft_printf("\tGot an %X on my exam\n", 16);
	printf("\tGot an %X on my exam\n", 16);

	printf("\ntesting negative hexadecimal\n");
	ft_printf("\tGot an %x on my exam\n", -16);
	printf("\tGot an %x on my exam\n", -16);

	printf("\ntesting BIG negative hexadecimal\n");
	ft_printf("\tGot an %X on my exam\n", -16);
	printf("\tGot an %X on my exam\n", -16);

	printf("\ntesting unsigned integer\n");
	ft_printf("\tKimi Raikkonen is number %u\n", 1);
	printf("\tKimi Raikkonen is number %u\n", 1);

	printf("\ntesting a negative unsigned integer\n");
	ft_printf("\tWow this ia big number %u\n", (1-2));
	printf("\tWow this ia big number %u\n", (1-2));

	printf("\ntesting a pointer\n");
	ft_printf("\tAddress: %p\n", str); 
	printf("\tAddress: %p\n", str);
	/*
	An unsigned is an integer that can never be negative. 
	If you take an unsigned 0 and subtract 1 from it, the result wraps around, 
	leaving a very large number (2^32-1 with the typical 32-bit integer size).
	*/
	printf("\ntesting octal\n");
	ft_printf("\tI guess this is an octal? %o == 12 ?\n", 10);
	printf("\tI guess this is an octal? %o == 12 ?\n", 10);

	printf("\ntesting zero-fill\n");
	ft_printf("\tYou miss 1%04d of the shots you don't take\n", 0);
	printf("\tYou miss 1%04d of the shots you don't take\n", 0);

	printf("\ntesting decimal formatting\n");
	ft_printf("\tDon't let this be devil's number: %.1f\n", 6.66);
	printf("\tDon't let this be devil's number: %.1f\n", 6.66);

	printf("\nTesting in all the conversion specifiers in one:\n");
	ft_printf("\t%c%s%p%d%i%o%u%x%X%f\n", 'a', str, str, 123, 456, 9, 11, 0xf, 0xf, 111.0);
	printf("\t%c%s%p%d%i%o%u%x%X%f\n", 'a', str, str, 123, 456, 9, 11, 0xf, 0xf, 111.0);

	printf("\ngeneral test:\n");
	printf("\t%% %%%1iiii%+0i1 %01i- #+i%011i- #%%%%\n", 123, 456, 789, 0);
	ft_printf("\t%% %%%1iiii%+0i1 %01i- #+i%011i- #%%%%\n", 123, 456, 789, 0);

	printf("\ntesting bad boi float\n");
	format = strdup("%.10f\n");
	i = 0;
	while (i < 9)
	{
		ft_printf(format, 1234567.123456789123456789);
		printf(format, 1234567.123456789123456789);
		fflush(NULL);
		format[3]++;
		i++;
	}
	free(format);

	printf("\nSpecial characters:\n");
	ft_printf("tab: \tBackspace\b form feed: \f, newline: \n carriage return:\n delete\r vertical tab: \v and a backslash: \\");
	printf("\n-------------------------------------------------------\n");
	printf("tab: \tBackspace\b form feed: \f, newline: \n carriage return:\n delete\r vertical tab: \v and a backslash: \\");

	printf("\nTesting width:\n");
	ft_printf("\t%*d\n", 5, 10);
	printf("\t%*d\n", 5, 10);

	printf("\nTesting width, test 2:\n");
	ft_printf("\t%5d\n", 10);
	printf("\t%5d\n", 10);
	exit(1);
/*  	printf("\ntesting a percent sign\n");
	ft_printf("\twooow 1000%% or 1000%\\n"); 
	printf("\twooow 1000%% or 1000%\\n");  */
}
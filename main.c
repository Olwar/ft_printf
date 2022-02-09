#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char *str = "Ma'am";
	
	printf("Hello");
	system("whoami");
	printf("\ntesting string:\n");
	ft_printf("\tHello\n");
	ft_printf("\tHello\n");
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
	printf("\ntesting float\n");
	ft_printf("\tSo far I've made %f on my programming career\n", 0.00);
	printf("\tSo far I've made %f on my programming career\n", 0.00);
	printf("\ntesting hexadecimal\n");
	ft_printf("\tGot an %x on my exam\n", 16);
	printf("\tGot an %x on my exam\n", 16);
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
	printf("\ntesting a percent sign\n");
	ft_printf("\twooow 1000%% or 1000\%\n"); 
	printf("\twooow 1000%% or 1000\%\n");
	printf("\ntesting octal\n");
	ft_printf("\tI guess this is an octal? %o Should be a b ?\n", 10);
	printf("\tI guess this is an octal? %o Should be a b ?\n", 10);
	printf("\ntesting zero-fill\n");
	ft_printf("\tYou miss 1%02d%% of the shots you don't take\n", 0);
	printf("\tYou miss 1%02d%% of the shots you don't take\n", 0);
	printf("\ntesting decimal formatting\n");
	ft_printf("\tDon't let this be devil's number: %.1f\n", 6.66);
	printf("\tDon't let this be devil's number: %.1f\n", 6.66);
	printf("\nSpecial characters:\n");
	ft_printf("tab: \tBackspace\b form feed: \f, newline: \n carriage return:\n delete\r vertical tab: \v and a backslash: \\");
	printf("tab: \tBackspace\b form feed: \f, newline: \n carriage return:\n delete\r vertical tab: \v and a backslash: \\");
}
#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"
#include <limits.h>

int main(void)
{
	char					*str = "Ma'am";
	char					*str2 = "19";
	char					*format;
	int						i;
	int						len;

	system("echo Nice to meet you $(whoami)");
	printf("\n1. mine, 2. unix: testing string:\n");
	ft_printf("\tHello\n");
	printf("\tHello\n");

	printf("\n1. mine, 2. unix: testing length:\n");
	len = ft_printf("\tShould return 19:\n");
	printf("%d", len);
	len = printf("\tShould return 19:\n");
	printf("%d", len);

	printf("\n1. mine, 2. unix: testing length, test2:\n");
	len = ft_printf("\tShould return %s:\n", str2);
	printf("%d", len);
	len = printf("\tShould return %s:\n", str2);
	printf("%d", len);

	printf("\n1. mine, 2. unix: testing length, test2:\n");
	len = ft_printf("\tShould return %x:\n", -19);
	printf("%d", len);
	len = printf("\tShould return %x:\n", -19);
	printf("%d", len);

	printf("\n1. mine, 2. unix: testing another string:\n");
	ft_printf("\tHello %s\n", str);
	printf("\tHello %s\n", str);

 	printf("\n1. mine, 2. unix: testing upper-case character\n");
	ft_printf("\tThis... is... %cPARTA!\n", 'S');
	printf("\tThis... is... %cPARTA!\n", 'S'); 

	printf("\n1. mine, 2. unix: testing lower-case character\n");
	ft_printf("\tThis... is... %canta! Ho ho ho!\n", 's');
	printf("\tThis... is... %canta! Ho ho ho!\n", 's');

	printf("\n1. mine, 2. unix: testing integer\n");
	ft_printf("\tIs this mambo number %d\n", 5);
	printf("\tIs this mambo number %d\n", 5);

	printf("\n1. mine, 2. unix: testing negative integer\n");
	ft_printf("\tIs this mambo number %d\n", -5);
	printf("\tIs this mambo number %d\n", -5);

	printf("\n1. mine, 2. unix: testing float\n");
	ft_printf("\tSo far I've made %f€ on my programming career\n", 0.00);
	printf("\tSo far I've made %f€ on my programming career\n", 0.00);

	printf("\n1. mine, 2. unix: testing hexadecimal\n");
	ft_printf("\tGot an %x on my exam\n", 16);
	printf("\tGot an %x on my exam\n", 16);

	printf("\n1. mine, 2. unix: testing BIG hexadecimal\n");
	ft_printf("\tGot an %X on my exam\n", 16);
	printf("\tGot an %X on my exam\n", 16);

	printf("\n1. mine, 2. unix: testing negative hexadecimal\n");
	ft_printf("\tGot an %x on my exam\n", -16);
	printf("\tGot an %x on my exam\n", -16);

	printf("\n1. mine, 2. unix: testing BIG negative hexadecimal\n");
	ft_printf("\tGot an %X on my exam\n", -16);
	printf("\tGot an %X on my exam\n", -16);

	printf("\n1. mine, 2. unix: testing hexadecimal with width modifier\n");
	ft_printf("\tGot an %10X on my exam\n", -16);
	printf("\tGot an %10X on my exam\n", -16);

	printf("\n1. mine, 2. unix: testing unsigned integer\n");
	ft_printf("\tKimi Raikkonen is number %u\n", 1);
	printf("\tKimi Raikkonen is number %u\n", 1);

	printf("\n1. mine, 2. unix: testing a negative unsigned integer\n");
	ft_printf("\tWow this ia big number %u\n", (1-2));
	printf("\tWow this ia big number %u\n", (1-2));

	printf("\n1. mine, 2. unix: testing a pointer\n");
	ft_printf("\tAddress: %p\n", str); 
	printf("\tAddress: %p\n", str);
	/*
	An unsigned is an integer that can never be negative. 
	If you take an unsigned 0 and subtract 1 from it, the result wraps around, 
	leaving a very large number (2^32-1 with the typical 32-bit integer size).
	*/
	printf("\n1. mine, 2. unix: testing octal\n");
	ft_printf("\tI guess this is an octal? %o == 12 ?\n", 10);
	printf("\tI guess this is an octal? %o == 12 ?\n", 10);

	printf("\n1. mine, 2. unix: testing zero-fill\n");
	ft_printf("\tYou miss 1%04d of the shots you don't take\n", 0);
	printf("\tYou miss 1%04d of the shots you don't take\n", 0);

	printf("\n1. mine, 2. unix: testing decimal formatting\n");
	ft_printf("\tDon't let this be devil's number: %.1f\n", 6.66);
	printf("\tDon't let this be devil's number: %.1f\n", 6.66);

	printf("\n1. mine, 2. unix: Testing in all the conversion specifiers in one:\n");
	ft_printf("\t%c%s%p%d%i%o%u%x%X%f\n", 'a', str, str, 123, 456, 9, 11, 0xf, 0xf, 111.0);
	printf("\t%c%s%p%d%i%o%u%x%X%f\n", 'a', str, str, 123, 456, 9, 11, 0xf, 0xf, 111.0);

	printf("\n1. mine, 2. unix: general test:\n");
	ft_printf("\t%% %%%1iiii%+0i1 %01i- #+i%011i- #%%%%\n", 123, 456, 789, 0);
	printf("\t%% %%%1iiii%+0i1 %01i- #+i%011i- #%%%%\n", 123, 456, 789, 0);

	printf("\n1. mine, 2. unix: testing bad boi float\n");
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

	printf("\n1. mine, 2. unix: Special characters:\n");
	ft_printf("tab: \tBackspace\b form feed: \f, newline: \n carriage return:\n delete\r vertical tab: \v and a backslash: \\");
	printf("\n1. mine, 2. unix: -------------------------------------------------------\n");
	printf("tab: \tBackspace\b form feed: \f, newline: \n carriage return:\n delete\r vertical tab: \v and a backslash: \\");

	printf("\n1. mine, 2. unix: Testing width:\n");
	ft_printf("\t%*d\n", 5, 10);
	printf("\t%*d\n", 5, 10);

	printf("\n1. mine, 2. unix: Testing width, test 2:\n");
	ft_printf("\t%5d\n", 10);
	printf("\t%5d\n", 10);

	printf("\n1. mine, 2. unix: Testing width with zero flag:\n");
	ft_printf("\t%05d\n", 10);
	printf("\t%05d\n", 10);
	
	printf("\n1. mine, 2. unix: Testing 42filechecker tests 1:\n");
	ft_printf("\t%10x\n", 42);
	printf("\t%10x\n", 42);

	printf("\n1. mine, 2. unix: Testing 42filechecker tests 2:\n");
	ft_printf("\t%-10x\n", 42);
	printf("\t%-10x\n", 42);

/* 	printf("\n1. mine, 2. unix: Testing 42filechecker tests:\n");
	ft_printf("\t%5%\n");
	printf("\t%5%\n"); */

	printf("\n1. mine, 2. unix: Testing 42filechecker tests 3:\n");
	ft_printf("\t%jx\n", 4294967296);
	printf("\t%jx\n", 4294967296);

	printf("\n1. mine, 2. unix: Testing 42filechecker tests 4:\n");
	ft_printf("\t%lx\n", 9223372036854775807);
	printf("\t%lx\n", 9223372036854775807);

	printf("\n1. mine, 2. unix: Testing 42filechecker tests 5:\n");
	ft_printf("\t%-5%\n");
	printf("\t%-5%\n");

	printf("\n1. mine, 2. unix: Testing 42filechecker tests 6:\n");
	len = ft_printf("\t%-15x\n", 542);
	printf("%d", len);
	len = printf("\t%-15x\n", 542);
	printf("%d", len);

	/* why doesn't print (null) */
	printf("\n1. mine, 2. unix: Testing moulitest tests 1:\n");
	ft_printf("\t{%s}\n", NULL);
	printf("\t{%s}\n", NULL);

	printf("\n1. mine, 2. unix: Testing moulitest tests 2:\n");
	len = ft_printf("\t%d\n", -42);
	printf("%d", len);
	len = printf("\t%d\n", -42);
	printf("%d", len);

	printf("\n1. mine, 2. unix: Testing moulitest tests 3:\n");
	ft_printf("\t%p\n", NULL);
	printf("\t%p\n", NULL);

	printf("\n1. mine, 2. unix: Testing moulitest tests 4:\n");
	len = ft_printf("\t%  %\n");
	printf("%d", len);
	len = printf("\t%  %\n");
	printf("%d", len);

	printf("\n1. mine, 2. unix: Testing moulitest tests 5:\n");
	ft_printf("\t%ld%ld\n", 0l, 42l);
	printf("\t%ld%ld\n", 0l, 42l);

	printf("\n1. mine, 2. unix: Testing moulitest tests 6:\n");
	ft_printf("\t%ld\n", LONG_MIN);
	printf("\t%ld\n", LONG_MIN);

	printf("\n1. mine, 2. unix: Testing moulitest tests 7:\n");
	ft_printf("\t%u\n", 4294967295);
	printf("\t%lu\n", 4294967295);

	printf("\n1. mine, 2. unix: Testing moulitest tests 8:\n");
	ft_printf("\t%lo, %lo\n", 0ul, ULONG_MAX);
	printf("\t%lo, %lo\n", 0ul, ULONG_MAX);

	printf("\n1. mine, 2. unix: Testing moulitest tests 9:\n");
	ft_printf("\t%llo, %llo\n", 0llu, ULLONG_MAX);
	printf("\t%llo, %llo\n", 0llu, ULLONG_MAX);

	printf("\n1. mine, 2. unix: Testing moulitest tests 9:\n");
	ft_printf("\t%x, %x\n", 0, UINT_MAX);
	printf("\t%x, %x\n", 0, UINT_MAX);

	printf("\n1. mine, 2. unix: Testing moulitest tests 10:\n");
	ft_printf("\t%lx, %lx\n", 0ul, ULONG_MAX);
	printf("\t%lx, %lx\n", 0ul, ULONG_MAX);

	printf("\n1. mine, 2. unix: Testing moulitest tests 11:\n");
	ft_printf("\t%lx, %lx\n", 0ul, ULONG_MAX);
	printf("\t%lx, %lx\n", 0ul, ULONG_MAX);

	printf("\n1. mine, 2. unix: Testing moulitest tests 12:\n");
	ft_printf("\t%#o\n", 42);
	printf("\t%#o\n", 42);

	printf("\n1. mine, 2. unix: Testing moulitest tests 13:\n");
	ft_printf("\t%#o\n", INT_MAX);
	printf("\t%#o\n", INT_MAX);

	printf("\n1. mine, 2. unix: Testing moulitest tests 14:\n");
	ft_printf("\t%#o\n", 0);
	printf("\t%#o\n", 0);

	printf("\n1. mine, 2. unix: Testing moulitest tests 15:\n");
	len = ft_printf("\t%#x\n", 42);
	printf("%d", len);
	len = printf("\t%#x\n", 42);
	printf("%d", len);

	printf("\n1. mine, 2. unix: Testing moulitest tests 16:\n");
	ft_printf("\t%#x\n", INT_MAX);
	printf("\t%#x\n", INT_MAX);

	printf("\n1. mine, 2. unix: Testing moulitest tests 17:\n");
	ft_printf("\t%#x\n", 0);
	printf("\t%#x\n", 0);

	printf("\n1. mine, 2. unix: Testing moulitest tests 18:\n");
	ft_printf("\t%#X\n", 42);
	printf("\t%#X\n", 42);

	printf("\n1. mine, 2. unix: Testing moulitest tests 19:\n");
	ft_printf("\t%#X\n", INT_MAX);
	printf("\t%#X\n", INT_MAX);

	printf("\n1. mine, 2. unix: Testing moulitest tests 20:\n");
	ft_printf("\t%#X\n", 0);
	printf("\t%#X\n", 0);

	printf("\n1. mine, 2. unix: Testing moulitest tests 21:\n");
	ft_printf("\t%x\n", -42);
	printf("\t%x\n", -42);

	printf("\n1. mine, 2. unix: Testing moulitest tests 22:\n");
	ft_printf("\t{%030X}\n", 0xFFFF);
	printf("\t{%030X}\n", 0xFFFF);

/* 	Doesn't compile for some reason:
	printf("\n1. mine, 2. unix: Testing moulitest tests 12:\n");
	ft_printf("\t%#c\n", 0);
	printf("\t%#c\n", 0);

	printf("\n1. mine, 2. unix: Testing moulitest tests 12:\n");
	ft_printf("\t%hhd\n", CHAR_MAX + 42);
	printf("\t%hhd\n", CHAR_MAX + 42);

	printf("\n1. mine, 2. unix: Testing moulitest tests 10:\n");
	ft_printf("\t%ho, %ho\n", 0, USHRT_MAX);
	printf("\t%ho, %ho\n", 0, USHRT_MAX);

	printf("\n1. mine, 2. unix: Testing 42filechecker tests 7:\n");
	ft_printf("\t%hhX\n", 294967296);
	printf("\t%hhX\n", 294967296);

	printf("\n1. mine, 2. unix: Testing 42filechecker tests 7:\n");
	ft_printf("\t%X\n", 4294967296);
	printf("\t%X\n", 4294967296);


	printf("\n1. mine, 2. unix: Testing 42filechecker tests 8:\n");
	ft_printf("\t%llX\n", 4294967296);
	printf("\t%llX\n", 4294967296); */

/*  	printf("\n1. mine, 2. unix: testing a percent sign\n");
	ft_printf("\twooow 1000%% or 1000%\\n"); 
	printf("\twooow 1000%% or 1000%\\n");  */
}
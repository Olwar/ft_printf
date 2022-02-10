#include "ft_print.h"

/*
va_list args = initialize arguments,
va_start = puts the args to memory
va_arg = pulls them from memory on by one
va_end = just to tell the compiler to end
*/

static const converter *my_array[12] =
{
	ft_putstr,
	ft_putnbr,
	ft_putnbr,
	ft_putfloat,
	ft_puthexa,
	ft_putunsigned,
	ft_putpointer,
	ft_putoctal,
	ft_putzerofill,
	ft_putdecimal
};

/* int	massive_if(char c, va_list args, int i)
{
	if (c == '%s')
		va_arg(args, char *)
		putstr
	else if (c == '%c')
		va_arg(args, char)
		putchar
	else if (c == '%d')
		va_arg(args, int)
		putnbr
	else if (c == '%f')
		va_arg(args, float)
		putfloat
	else if (c == '%x')
		va_arg(args, int)
		puthexa
	else if (c == '%u')
		va_arg(args, unsigned int)
		putunsigned
	else if (c == '%p')
		va_arg(args, void *)
		putpointer
	else if (c == '%%' || '\%')
		putchar('%')
	else if (c == '%o')
		va_arg(args, int)
		putoctal
	else if (c == '%f')
		va_arg(args, float)
	else if (c == '%0')
		va_arg(args, int)
		putzerofill
	else if (c == '%.')
		va_arg(args, float)
		putdecimal
	else if (c == '\n' || c == '\t' || c == '\b' || c == '\f' || c == '\r' || \
	c == '\v' || c == '\\' || c == '\n' || )
		putchar(c)
	else
		putstr(error)

} */

/* make flag 0-4 index, fieldt_with 5-... etc... */

void	add_info(t_list *pr)
{
	if (pr->array)
	{
		pr->temp = ft_intdup(pr->array, sizeof(pr->array) / sizeof(int));
		free(pr->array);
	}
	pr->array = ft_intdup(pr->temp, sizeof(pr->temp) / sizeof(int) + sizeof(int));
}

void	checker(t_list *pr, char c)
{
	while (pr->flag[pr->i])
	{
		if (pr->flag[pr->i] == c)
			add_info(&*pr);
	}
}

void	initializer(char c)
{
	t_list pr;
	
	pr.i = 0;
	pr.flag = "#0- +";
	pr.field_width = "123456789*";
	pr.precision = ".";
	pr.length_modifier = "hl"; /*hh, h, l, ll*/
	pr.conversion_specifier = "diouxX";
	pr.percent = "%";
	checker(&pr, c);
}

int	ft_printf(const char *format, ...)
{
	int	i;
	va_list args;

	i = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
			initializer(format[i + 1], args, i);
		write(1, format[i], 1);
	}
	va_end(args);
}
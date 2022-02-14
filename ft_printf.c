#include "ft_printf.h"

/*
va_list args = initialize arguments,
va_start = puts the args to memory
va_arg = pulls them from memory on by one
va_end = just to tell the compiler to end
*/

static const converter *myarray[31] =
{
	ft_puthash, /* if o then first char is 0, if x then nonzero result = 0x */
	ft_putzerofill,
	ft_justify,
	ft_putspace, /* print space if positive number, if not plus*/
	ft_putsign, /* print + or - depending on number */
	ft_putwidth,
	ft_putwidth,
	ft_putwidth,
	ft_putwidth,
	ft_putwidth,
	ft_putwidth,
	ft_putwidth,
	ft_putwidth,
	ft_putwidth,
	ft_putwidth,
	ft_putprecision,
	ft_puthh,
	ft_puthh,
	ft_putll,
	ft_putll,
	ft_puth,
	ft_putl,
	ft_putL,
	ft_putnbr,
	ft_putnbr_unsigned,
	ft_putoctal,
	ft_puthexa,
	ft_puthexa,
	ft_putchar,
	ft_putstr,
	ft_putpointer,
	ft_putfloat,
	ft_putperc
};

void	add_info(t_list *pr)
{
	if (pr->info_array)
	{
		pr->temp = ft_intdup(pr->info_array, sizeof(pr->info_array) / sizeof(int));
		free(pr->info_array);
	}
	pr->info_array = ft_append(pr->temp, pr->i, sizeof(pr->temp) / sizeof(int) + sizeof(int));
}

void	checker(t_list *pr, char c)
{
	while (pr->flag[pr->i])
	{
		if (pr->flag[pr->i] == c)
			add_info(&*pr);
		pr->i++;
	}
	while (pr->field_width[pr->i])
	{
		if (pr->field_width[pr->i] == c)
			add_info(&*pr);
		pr->i++;
	}
	if (pr->precision[pr->i] == c)
		add_info(&*pr);
	pr->i++;
	while (pr->length_modifier[pr->i])
	{
		if (pr->length_modifier[pr->i] == c)
			add_info(&*pr);
		pr->i++;
	}
	while (pr->conversion_specifier[pr->i])
	{
		if (pr->conversion_specifier[pr->i] == c)
			add_info(&*pr);
		pr->i++;
	}
	if (pr->percent[pr->i] == c)
		add_info(&*pr);
}

void	initializer(char c, va_list args, int *i)
{
	t_list pr;
	/* take care that c is not z */
	pr.i = 0;
	pr.flag = "#0- +";
	pr.field_width = "zzzzz123456789*";
	pr.precision = "zzzzzzzzzzzzzzz.";
	pr.length_modifier = "zzzzzzzzzzzzzzzhhllhlL"; /*hh, h, l, ll*/
	pr.conversion_specifier = "zzzzzzzzzzzzzzzzzzzzzzzdiouxXf";
	pr.percent = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzz%";
	checker(&pr, c);
	pr.i = 0;
	while (pr.info_array[pr.i] != NULL)
	{
		converter[pr.info_array[pr.i]](args, pr.info_array, pr.i);
		pr.i++;
	}
}

int	ft_printf(const char *format, ...)
{
	int	i;
	va_list args;
	char *special_string_part

	i = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{	/* make i skip special character */
			special_string_part = initializer(format[i + 1], args, &i); 
			special_printer_for_my_special_baby(special_string_part);
		}
		else
			write(1, format[i], 1);
	}
	va_end(args);
}
#include <unistd.h>
#include <stdarg.h>

/*
va_list args = initialize arguments,
va_start = puts the args to memory
va_arg = pulls them from memory on by one
va_end = just to tell the compiler to end
*/

int	massive_if(char c, va_list args, int i)
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

}

void	ft_printf(char *str, ...)
{
	int	i;
	va_list args;

	i = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		i = massive_if(str[i], args, i);
		write(1, str[i], 1);
	}
	va_end(args);
}
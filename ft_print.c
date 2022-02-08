#include <unistd.h>
#include <stdarg.h>

/*
va_list args = initialize arguments,
va_start = puts the args to memory
va_arg = pulls them from memory on by one
va_end = just to tell the compiler to end
*/

void	massive_if(char c, va_list args)
{
	if (c == "%s")
		va_arg(args, char)
		putstr
	if (c == "%c")
		va_arg(args, char)
		putchar
	if (c == "%d")
		va_arg(args, char)
		putnbr
	if (c == "%f")
	...

}

void	ft_printf(char *str, ...)
{
	int	i;
	va_list args;

	i = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		write(1, str[i], 1);
		massive_if(str[i], args);
	}
	va_end(args);
}
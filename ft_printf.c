#include "ft_printf.h"

/*
va_list args = initialize arguments,
va_start = puts the args to memory
va_arg = pulls them from memory on by one
va_end = just to tell the compiler to end
*/

static const t_converter *myarray[33] =
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
	ft_putnbr_printf,
	ft_putnbr_unsigned,
	ft_putoctal,
	ft_puthexa_lower,
	ft_puthexa_upper,
	ft_putchar,
	ft_putstr_printf,
	ft_putpointer,
	ft_putfloat,
	ft_putperc
};

/* void	add_info(t_prlist *pr)
{
	if (pr->info_array)
	{
		pr->temp = ft_intdup \
		(pr->info_array, sizeof(pr->info_array) / sizeof(int));
		free(pr->info_array);
	}
	pr->info_array = ft_append \
	(pr->temp, pr->i, sizeof(pr->temp) / sizeof(int) + sizeof(int));
} */

void	add_at_end(t_node *head, int data)
{
	t_node *ptr;
	t_node *temp;

	ptr = head;
	temp = (t_node *)malloc(sizeof(t_node));
	temp->data = data;
	temp->next = NULL;
	while(ptr->next != NULL)
		ptr = ptr->next;
	ptr->next = temp;
}

t_node	*checker(t_prlist *pr, char *format_part)
{
	int	j;
	t_node *head;

	head = NULL;
	j = -1;
	while (format_part[++j] != '\0')
	{
		pr->i = 0;
		while (pr->all_the_info[pr->i])
		{
			if (pr->all_the_info[pr->i] == format_part[j])
			{
				if (head == NULL)
					head = ft_lstnew(pr->i, sizeof(int));
				else
					add_at_end(head, pr->i);
			}
			pr->i++;
		}
	}
	return (head);
}

char	*initializer(char *format_part, va_list args)
{
	t_prlist	pr;
	t_node		*head;
	t_node		*ptr;
	/* to remember:    0123456789012345678901234567890123 */
	pr.all_the_info = "#0- +123456789*.hhllhlLdiouxXcspf%";
	head = checker(&pr, format_part);
	ptr = head;
	pr.i = 0;
/* 	while (pr.info_array[pr.i] != NULL)
	{
		if ((pr.i >= 0 && pr.i <= 14) || (pr.i >= 23))
		{
			myarray[pr.info_array[pr.i]](args, pr.info_array);
		}
		pr.i++;
	} */
	while (ptr != NULL)
	{
		if ((ptr->data >= 0 && ptr->data <= 14) || (ptr->data >= 23))
		{
			myarray[ptr->data](args, head);
		}
		ptr = ptr->next;
	}
}


int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	args;
	char	*special_string_part;
	char	*format_part;

	i = -1;
	va_start(args, format);
	while (format[++i] != '\0')
	{
		if (format[i] == '%')
		{
			format_part = cutter(format, &i); /* cuts the formatter part */
			initializer(format_part, args); 
			/* special_printer_for_my_special_baby(special_string_part); */
			i--;
		}
		else
			write(1, format[i], 1);
	}
	va_end(args);
}
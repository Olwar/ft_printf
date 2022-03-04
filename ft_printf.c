#include "ft_printf.h"

/*
va_list args = initialize arguments,
va_start = puts the args to memory
va_arg = pulls them from memory on by one
va_end = just to tell the compiler to end
*/

t_converter *myarray[33] =
{
	ft_puthash, /* if o then first char is 0, if x then nonzero result = 0x */
	ft_putwidth,
	ft_literally_do_nothing,
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
	ft_literally_do_nothing,
	ft_literally_do_nothing,
	ft_literally_do_nothing,
	ft_literally_do_nothing,
	ft_literally_do_nothing,
	ft_literally_do_nothing,
	ft_literally_do_nothing,
	ft_putnbr_printf,
	ft_putnbr_printf,
	ft_putoctal,
	ft_putnbr_printf_unsigned,
	ft_puthexa_lower,
	ft_puthexa_upper,
	ft_putchar_printf,
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

void	*ft_zmemcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dst_copy;
	unsigned char	*src_copy;
	size_t			i;

	if (src == NULL && dst == NULL)
		return (NULL);
	i = 0;
	src_copy = (unsigned char *)src;
	dst_copy = (unsigned char *)dst;
	while (i < n)
	{
		dst_copy[i] = src_copy[i];
		i++;
	}
	return (dst_copy);
}

t_node	*ft_zlstnew(int content, size_t	content_size)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (new_node == NULL)
		return (NULL);
	if (content != 0)
	{
		new_node->data = (size_t)malloc(content_size);
		if (new_node == NULL)
		{
			free(new_node);
			return (NULL);
		}
		new_node->data = content;
		new_node->next = NULL;
	}
	else
	{
		new_node->data = 0;
		new_node->next = NULL;
	}
	return (new_node);
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
					head = ft_zlstnew(pr->i, sizeof(int));
				else
					add_at_end(head, pr->i);
				break;
			}
			pr->i++;
		}
	}
	return (head);
}

int	initializer(char *format_part, va_list args)
{
	t_prlist	pr;
	t_node		*head;
	t_node		*ptr;
	int			len;
	/* to remember:    0123456789012345678901234567890123 */
	pr.all_the_info = "#0- +123456789*.hhllhldiouxXcspf%";
	head = checker(&pr, format_part);
	ptr = head;
	pr.i = 0;
	len = 0;
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
		if (ptr->data == 15)
			while (ptr->data == 1 || ptr->data == 15 || (ptr->data >= 5 && ptr->data <= 13))
				ptr = ptr->next;
		if ((ptr->data >= 0 && ptr->data <= 14) || ptr->data >= 22)
		{
			if (ptr->data == 2)
				while (ptr->data >= 0 && ptr->data <= 13)
					ptr = ptr->next;
			len += myarray[ptr->data](args, head, format_part);
			if ((ptr->data == 1 && !(ptr->next->data >= 22 && ptr->next->data <= 32)) || \
			((ptr->data >= 5 && ptr->data <= 13) && !(ptr->next->data >= 22 && ptr->next->data <= 32)))
				ptr = ptr->next;
		}
		ptr = ptr->next;
	}
	return (len);
}


int	ft_printf(const char *format, ...)
{
	int			i;
	va_list		args;
	char		*format_part;
	int			length;

	va_start(args, format);
	if (!format)
		return (-1);
	i = -1;
	length = 0;
	while (format[++i] != '\0')
	{
		if (format[i] == '%')
		{
			format_part = ft_cutter(format, &i, args); /* cuts the formatter part */
			if (format_part == NULL)
				return (0);
			length += initializer(format_part, args); 
			/* special_printer_for_my_special_baby(special_string_part); */
		}
		else
		{
			write(1, &format[i], 1);
			length++;
		}
	}
	va_end(args);
	return (length);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cutter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olli <olli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 09:59:44 by olwar             #+#    #+#             */
/*   Updated: 2022/03/06 14:19:49 by olli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_zstrsub(char const *s, unsigned int start, size_t len)
{
	char	*s2;
	size_t	a;

	a = 0;
	s2 = (char *)malloc(sizeof(char) * len + 1);
	if (s2 == NULL)
		return (NULL);
	while (a != len)
	{
		s2[a] = s[start];
		start++;
		a++;
	}
	s2[a] = '\0';
	return (s2);
}

int		real_char(char c)
{
	int		i;
	char	*data = "#0- +123456789*.hhllhldiouxXcspf%";

	i = -1;
	while (data[++i] != '\0')
	{
		if (data[i] == c)
			return (1);
	}
	return (0);
}

char	*ft_cutter(const char *format, int *i, va_list args)
{
	int		start;
	char	*cut_string;
	int		flag;

	(void)args;
	start = *i;
	flag = 0;
	cut_string = NULL;
	(*i)++;
	while (format[*i] != '\0')
	{
		if (!(real_char(format[*i])))
			return (NULL);
		if (format[*i] == 'd' || format[*i] == 'i' || format[*i] == 'o' || \
		format[*i] == 'u' || format[*i] == 'x' || format[*i] == 'X' \
		|| format[*i] == 'c' || format[*i] == 's' || format[*i] == 'p' \
		|| format[*i] == 'f' || format[*i] == '%')
		{
			cut_string = ft_zstrsub(format, start + 1, (*i) - start);
			flag = 1;
			break ;
		}
		(*i)++;
	}
	if (flag == 1)
		return (cut_string);
	else
		return (NULL);
}
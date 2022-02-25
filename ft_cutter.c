/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cutter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olwar <olwar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 09:59:44 by olwar             #+#    #+#             */
/*   Updated: 2022/02/25 09:31:17 by olwar            ###   ########.fr       */
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

char	*ft_cutter(const char *format, int *i)
{
	int		start;
	char	*cut_string;

	start = *i;
	cut_string = NULL;
	(*i)++;
	while (format[*i] != '\0')
	{
		if (format[*i] == 'd' || format[*i] == 'i' || format[*i] == 'o' || \
		format[*i] == 'u' || format[*i] == 'x' || format[*i] == 'X' \
		|| format[*i] == 'c' || format[*i] == 's' || format[*i] == 'p' \
		|| format[*i] == 'f' || format[*i] == '%')
		{
			cut_string = ft_zstrsub(format, start + 1, (*i) - start);
			break ;
		}
		(*i)++;
	}
	return (cut_string);
}
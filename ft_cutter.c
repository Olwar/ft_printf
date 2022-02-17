/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cutter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olwar <olwar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 09:59:44 by olwar             #+#    #+#             */
/*   Updated: 2022/02/17 15:31:50 by olwar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_cutter(char *format, int *i)
{
	int		start;
	char	*cut_string;

	start = *i;
	while (format[*i] != '\0')
	{
		if (format[*i] == 'd' || format[*i] == 'i' || format[*i] == 'o' || \
		format[*i] == 'u' || format[*i] == 'x' || format[*i] == 'X' \
		|| format[*i] == 'c' || format[*i] == 's' || format[*i] == 'p' \
		|| format[*i] == 'f')
		{
			cut_string = ft_strsub(format, start, i);
			break ;
		}
		*i++;
	}
	return (cut_string);
}
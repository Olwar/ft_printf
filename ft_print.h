/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oairola <oairola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:26:06 by oairola           #+#    #+#             */
/*   Updated: 2022/02/10 16:34:17 by oairola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_H
# define FT_PRINT_H

#include <unistd.h>
#include <stdarg.h>
#include "libft/libft.h"

typedef char	converter(va_list args, char c, int i);

typedef struct t_list
{
	char	*flag;
	char	*field_width;
	char 	*precision;
	char	*length_modifier;
	char	*conversion_specifier;
	char	*percent;
	int		*array;
	int		*temp;
	int		i;
}				t_list;

#endif
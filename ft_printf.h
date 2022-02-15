/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olwar <olwar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 12:14:24 by oairola           #+#    #+#             */
/*   Updated: 2022/02/15 10:23:14 by olwar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include "libft/libft.h"
#include <unistd.h>
#include <stdarg.h>

typedef struct t_list
{
	int	i;
	
}				t_list;


typedef void converter(va_list args, int *info_array);
void	ft_puthash(va_list args, int *info_array);
void	ft_putzerofill(va_list args, int *info_array);
void	ft_putspace(va_list args, int *info_array);
void	ft_putsign(va_list args, int *info_array);

#endif 
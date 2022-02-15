/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olwar <olwar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 12:14:24 by oairola           #+#    #+#             */
/*   Updated: 2022/02/15 15:46:41 by olwar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdarg.h>

typedef struct t_list
{
	int		i;
	int		temp;
	char	*all_the_info;
	int		*info_array;
}				t_list;


typedef void	t_converter(va_list args, int *info_array);

void	ft_puthash(va_list args, int *info_array);
void	ft_putzerofill(va_list args, int *info_array);
void	ft_putspace(va_list args, int *info_array);
void	ft_putsign(va_list args, int *info_array);
void	ft_putwidth(va_list args, int *info_array);
void	ft_put_d_and_i(va_list args, char *info_array);
void	ft_putoctal(va_list args, int *info_array);
void	ft_putfloat(va_list args, int *info_array);
void	ft_putstr_printf(va_list args, int *info_array);
int		*ft_append(int const *src, int appendable, size_t len);

#endif 
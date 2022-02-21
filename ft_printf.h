/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oairola <oairola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 12:14:24 by oairola           #+#    #+#             */
/*   Updated: 2022/02/21 16:10:50 by oairola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdarg.h>

typedef struct t_printflist
{
	int		i;
	int		temp;
	char	*all_the_info;
	int		*info_array;
}				t_prlist;

typedef struct t_node
{
	int				data;
	struct t_node	*next;
}			t_node;


typedef void	t_converter(va_list args, t_node *head, char *format_part);

void	ft_puthash(va_list args, t_node *head, char *format_part);
void	ft_putzerofill(va_list args, t_node *head, char *format_part);
void	ft_putspace(va_list args, t_node *head, char *format_part);
void	ft_putsign(va_list args, t_node *head, char *format_part);
void	ft_putwidth(va_list args, t_node *head, char *format_part);
void	ft_put_d_and_i(va_list args, t_node *head, char *format_part);
void	ft_putoctal(va_list args, t_node *head, char *format_part);
void	ft_putfloat(va_list args, t_node *head, char *format_part);
void	ft_putstr_printf(va_list args, t_node *head, char *format_part);
/* int		*ft_append(int const *src, int appendable, size_t len); */
void	ft_puthexa_lower(va_list args, t_node *head, char *format_part);
void	ft_puthexa_upper(va_list args, t_node *head, char *format_part);
void	ft_putperc(va_list args, t_node *head, char *format_part);
void	ft_putpointer(va_list args, t_node *head, char *format_part);
void	ft_literally_do_nothing(va_list args, t_node *head, char *format_part);
char	*ft_cutter(const char *format, int *i);
int		ft_printf(const char *format, ...);
void	ft_float(double myfloat, int limiter);
void	ft_putchar_printf(va_list args, t_node *head, char *format_part);
void	ft_error_exit(char *str);
void	ft_putnbr_printf(va_list args, t_node *head, char *format_part);

#endif 
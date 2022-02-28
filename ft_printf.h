/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oairola <oairola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 12:14:24 by oairola           #+#    #+#             */
/*   Updated: 2022/02/28 15:43:20 by oairola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

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


typedef int	t_converter(va_list args, t_node *head, char *format_part);

int	ft_puthash(va_list args, t_node *head, char *format_part);
int	ft_putzerofill(va_list args, t_node *head, char *format_part);
int	ft_putspace(va_list args, t_node *head, char *format_part);
int	ft_putsign(va_list args, t_node *head, char *format_part);
int	ft_putwidth(va_list args, t_node *head, char *format_part);
int	ft_put_d_and_i(va_list args, t_node *head, char *format_part);
int	ft_putoctal(va_list args, t_node *head, char *format_part);
int	ft_putfloat(va_list args, t_node *head, char *format_part);
int	ft_putstr_printf(va_list args, t_node *head, char *format_part);
int	ft_puthexa_lower(va_list args, t_node *head, char *format_part);
int	ft_puthexa_upper(va_list args, t_node *head, char *format_part);
int	ft_putperc(va_list args, t_node *head, char *format_part);
int	ft_putpointer(va_list args, t_node *head, char *format_part);
int	ft_literally_do_nothing(va_list args, t_node *head, char *format_part);
char	*ft_cutter(const char *format, int *i);
int		ft_printf(const char *format, ...);
int	ft_float(double myfloat, int limiter);
int	ft_putchar_printf(va_list args, t_node *head, char *format_part);
int	ft_putnbr_printf(va_list args, t_node *head, char *format_part);
void	ft_error_exit(char *str);

#endif 
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkzero.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olli <olli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 12:32:19 by olwar             #+#    #+#             */
/*   Updated: 2022/03/06 16:08:11 by olli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_checkzero(va_list args, t_node *head, char *format_part)
{
	int			j;
	int			zero_flag;
	int			number_flag;

	j = 0;
	zero_flag = -1;
	number_flag = -1;
	(void)(args);
	(void)head;
	while (format_part[j] != '\0')
	{
		if (format_part[j] == '0' && zero_flag == -1)
			zero_flag = j;
		if ((format_part[j] >= '1' && format_part[j] <= '9') && number_flag == -1)
			number_flag = j;
		j++;
	}
	if ((zero_flag < number_flag && zero_flag != -1))
		return (1);
	else
		return (0);
}
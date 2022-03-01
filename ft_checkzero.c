/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkzero.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olwar <olwar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 12:32:19 by olwar             #+#    #+#             */
/*   Updated: 2022/03/01 12:51:13 by olwar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_checkzero(va_list args, t_node *head, char *format_part)
{
	int			j;
	int			zero_flag;
	int			number_flag;

	j = 0;
	zero_flag = 0;
	number_flag = 0;
	(void)(args);
	(void)head;
	while (format_part[j] != '\0')
	{
		j++;
		if (format_part[j] == '0')
			zero_flag = j;
		if (format_part[j] >= '1' && format_part[j] <= '9')
			number_flag = j;
	}
	if (zero_flag < number_flag)
		return (1);
	else
		return (0);
}
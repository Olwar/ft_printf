/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_literally_do_nothing.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oairola <oairola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:09:06 by olwar             #+#    #+#             */
/*   Updated: 2022/02/28 15:47:42 by oairola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_literally_do_nothing(va_list args, t_node *head, char *format_part)
{
	(void) head;
	(void) args;
	(void) format_part;
	write(1, "doing nothing", 14);
	return (0);
}
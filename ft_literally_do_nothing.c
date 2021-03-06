/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_literally_do_nothing.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olwar <olwar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:09:06 by olwar             #+#    #+#             */
/*   Updated: 2022/03/01 12:57:53 by olwar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_literally_do_nothing(va_list args, t_node *head, char *format_part)
{
	(void) head;
	(void) args;
	(void) format_part;
	return (0);
}
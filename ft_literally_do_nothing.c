/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_literally_do_nothing.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oairola <oairola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:09:06 by olwar             #+#    #+#             */
/*   Updated: 2022/02/21 14:30:46 by oairola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_literally_do_nothing(va_list args, t_node *head, char *format_part)
{
	(void) head;
	(void) args;
	(void) format_part;
	printf("doing nothing");
}
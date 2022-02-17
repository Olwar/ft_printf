/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olwar <olwar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:10:58 by olwar             #+#    #+#             */
/*   Updated: 2022/02/17 14:24:54 by olwar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putpointer(va_list args, t_node *head, char *format_part)
{
	void	*ptr;

	ptr = va_arg(args, void *);
	write(1, &ptr, ft_strlen(&ptr));
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dot_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olli <olli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 18:13:05 by olli              #+#    #+#             */
/*   Updated: 2022/03/06 18:16:43 by olli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_dot_number(char *format_part)
{
    int     value;
    char    *for_atoi;
    
    for_atoi = ft_strchr(format_part, '.');
    if (for_atoi != 0)
    {
        for_atoi++;
        value = ft_atoi(for_atoi);
        return (value);
    }
    return (0);
}
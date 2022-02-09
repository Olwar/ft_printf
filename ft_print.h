/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oairola <oairola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:26:06 by oairola           #+#    #+#             */
/*   Updated: 2022/02/09 15:20:00 by oairola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_H
# define FT_PRINT_H

#include <unistd.h>
#include <stdarg.h>
#include "libft/libft.h"

typedef char	converter(va_list args, char c, int i);

/*define numbers for all flags*/

# define hh 1
# define h 2
# define l 3
# define ll 4
# define f 5
# define l 6
# define L 7
# define d 8
# define i 9
# define o 10
# define u 11
# define x 12
# define X 13
# define % 14
# define # 15
# define - 16
# define + 17

#endif
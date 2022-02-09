/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oairola <oairola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:56:50 by kslotova          #+#    #+#             */
/*   Updated: 2022/01/25 15:55:14 by oairola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_intdup(int const *src, size_t len)
{
	int	*p;

	p = malloc(len * sizeof(int));
	ft_memcpy(p, src, len * sizeof(int));
	return (p);
}

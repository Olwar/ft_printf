/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oairola <oairola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:58:31 by kslotova          #+#    #+#             */
/*   Updated: 2022/01/25 15:55:19 by oairola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_intnew(int size)
{
	int	*array;

	array = (int *)malloc(sizeof(int) * size);
	ft_bzero(array, sizeof(int) * size);
	return (array);
}

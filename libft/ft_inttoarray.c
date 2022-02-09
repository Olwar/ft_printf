/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inttoarray.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oairola <oairola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:18:34 by oairola           #+#    #+#             */
/*   Updated: 2022/01/25 15:55:25 by oairola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*inttoarray(int n)
{
	int	len;
	int	*array;
	int	i;
	int	orig;

	orig = n;
	i = 0;
	len = 0;
	if (n < 0)
		len++;
	while (n / 10 != 0)
	{
		len++;
		n = n / 10;
	}
	array = (int *)malloc(sizeof(int) * len + 1);
	n = orig;
	while (n != 0)
	{
		array[i++] = n;
		n = n / 10;
	}
	return (array);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oairola <oairola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 13:16:56 by oairola           #+#    #+#             */
/*   Updated: 2022/01/24 11:18:48 by oairola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_putlongnbr(long int n, int *array, int i)
{
	if (n / 10 != 0)
	{
		ft_putlongnbr(n / 10, array, i);
		ft_putlongnbr(n % 10, array, i);
	}
	else
	{
		array[i] = (n + '0');
		i++;
	}
	return (array);
}

int	*inttoarray(int n)
{
	long int	a;
	int			*array;
	int			i;

	i = 0;
	array = (int *)malloc(sizeof(int) * 8);
	a = (long int)n;
	array = ft_putlongnbr(a, array, i);
	return (array);
}

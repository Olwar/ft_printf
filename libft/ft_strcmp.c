/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oairola <oairola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 13:46:11 by oairola           #+#    #+#             */
/*   Updated: 2022/01/26 10:03:39 by oairola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	unsigned char	*s1_copy;
	unsigned char	*s2_copy;

	if (s1[0] == '\0' && s2[0] == '\0')
	{
		return (0);
	}
	s1_copy = (unsigned char *)s1;
	s2_copy = (unsigned char *)s2;
	i = 0;
	while (s1_copy[i] != '\0')
	{
		if (s1_copy[i] != s2_copy[i])
			return (s1_copy[i] - s2_copy[i]);
		i++;
	}
	if (s2_copy[i] == '\0')
		return (0);
	else
		return (s1_copy[i] - s2_copy[i]);
	return (0);
}

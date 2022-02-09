/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oairola <oairola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:24:33 by oairola           #+#    #+#             */
/*   Updated: 2021/11/16 11:40:34 by oairola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int	i;
	int	a;

	a = 0;
	i = 0;
	while (s1[i] != '\0')
		i++;
	while (s2[a] != '\0')
		s1[i++] = s2[a++];
	s1[i] = '\0';
	return (s1);
}

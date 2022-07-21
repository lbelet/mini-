/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelet <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 09:00:20 by lbelet            #+#    #+#             */
/*   Updated: 2021/10/20 09:14:49 by lbelet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*dst;
	int		i;
	int		j;

	i = 0;
	j = 0;
//	dst = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
//	if (!dst)
//		return (NULL);
	if (!s1)
	{
		dst = ft_strdup(s2);
		return (dst);
	}
	dst = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!dst)
		return (NULL);
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		dst[i + j] = s2[j];
		j++;
	}
	dst[i + j] = '\0';
//	free(s1);
	return (dst);
}

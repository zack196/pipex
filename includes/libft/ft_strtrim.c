/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-oirg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 23:45:34 by zel-oirg          #+#    #+#             */
/*   Updated: 2023/11/29 02:08:06 by zel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	apartien(const char c, const char *str)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	int		last;
	int		first;
	char	*res;
	int		i;

	if (!s1 || !set)
		return (NULL);
	first = 0;
	while (apartien(s1[first], set) && s1[first])
		first++;
	last = ft_strlen(s1);
	while (apartien(s1[last - 1], set) && first < last)
		last--;
	res = (char *)malloc((last - first + 1) * sizeof(*s1));
	if (!res)
		return (NULL);
	i = 0;
	while (first < last)
		res [i++] = s1[first++];
	res [i] = 0;
	return (res);
}

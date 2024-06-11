/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-oirg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 00:23:30 by zel-oirg          #+#    #+#             */
/*   Updated: 2023/11/26 19:38:56 by zel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	test(const char *str, const char *need)
{
	while (*str == *need && *need && *str)
	{
		need++;
		str++;
	}
	if (*need == 0)
		return (1);
	return (0);
}

char	*ft_strnstr(const char *str, const char *need, size_t n)
{
	size_t	i;

	if (ft_strlen(need) == 0)
		return ((char *)str);
	i = 0;
	while (i <= n - ft_strlen(need) && n && *str && n >= ft_strlen(need))
	{
		if (test(str, need) == 1)
			return ((char *)str);
		str++;
		i++;
	}
	return (NULL);
}

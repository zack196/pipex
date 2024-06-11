/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-oirg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:40:15 by zel-oirg          #+#    #+#             */
/*   Updated: 2023/12/01 00:30:32 by zel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	r;

	i = 0;
	if (!dest && size == 0)
		return (ft_strlen(src));
	r = ft_strlen(dest);
	while (*dest)
		dest++;
	while (src[i] && i + r + 1 < size)
	{
		*dest = src[i];
		i++;
		dest++;
	}
	*dest = 0;
	if (r > size)
		r = size;
	return (r + ft_strlen(src));
}

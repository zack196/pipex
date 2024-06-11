/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-oirg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:27:13 by zel-oirg          #+#    #+#             */
/*   Updated: 2023/11/28 22:35:47 by zel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dp;
	const unsigned char	*sp;

	dp = (unsigned char *)dst;
	sp = (const unsigned char *)src;
	if (!dp && !sp)
		return (NULL);
	if (dst < src)
		return (ft_memcpy(dst, src, len));
	while (len-- && len >= 0)
	{
		*(dp + len) = *(sp + len);
	}
	return (dst);
}

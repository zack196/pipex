/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-oirg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:54:05 by zel-oirg          #+#    #+#             */
/*   Updated: 2023/11/06 20:48:26 by zel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num_elements, size_t elements_size)
{
	void	*res;

	if (num_elements > 0 && SIZE_MAX / num_elements < elements_size)
		return (NULL);
	res = malloc(num_elements * elements_size);
	if (!res)
		return (0);
	ft_bzero(res, num_elements * elements_size);
	return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-oirg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 21:01:18 by zel-oirg          #+#    #+#             */
/*   Updated: 2023/11/28 23:13:19 by zel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nm;

	nm = n;
	if (nm < 0)
	{
		ft_putchar_fd('-', fd);
		nm = -nm;
	}
	if (nm < 10)
	{
		ft_putchar_fd(nm + '0', fd);
	}
	else
	{
		ft_putnbr_fd(nm / 10, fd);
		ft_putnbr_fd(nm % 10, fd);
	}
}

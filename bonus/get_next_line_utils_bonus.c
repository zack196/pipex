/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-oirg <zel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 08:12:35 by zel-oirg          #+#    #+#             */
/*   Updated: 2024/06/09 08:12:36 by zel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	chec_new_line(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (*(s + i))
	{
		if (*(s + i) == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	ft_str_len(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (*(s + i))
		i++;
	return (i);
}

char	*ft_str_dup(char *s, int len)
{
	char	*res;
	int		i;

	if (!s || !len)
		return (NULL);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	i = -1;
	while (++i < len)
		res[i] = s[i];
	res[i] = '\0';
	return (res);
}

char	*ft_join(char *s1, char *s2)
{
	char	*res;
	int		i;
	int		j;

	if (s1 && !s2)
		return (ft_str_dup(s1, ft_str_len(s1)));
	else if (!s1 && s2)
		return (ft_str_dup(s2, ft_str_len(s2)));
	else if (!s1 && !s2)
		return (free(s1), s1 = NULL, NULL);
	res = (char *)malloc(sizeof (char) * (ft_str_len(s1) + ft_str_len(s2) + 1));
	if (!res)
		return (free(s1), s1 = NULL, NULL);
	i = 0;
	j = 0;
	while (*(s1 + i))
		res[j++] = s1[i++];
	i = 0;
	while (*(s2 + i))
		res[j++] = s2[i++];
	res[j] = '\0';
	return (free(s1), s1 = NULL, res);
}

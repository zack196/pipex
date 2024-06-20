/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-oirg <zel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 17:59:55 by zel-oirg          #+#    #+#             */
/*   Updated: 2024/06/20 18:16:00 by zel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*handel_space(char *str)
{
	char	*tmp;
	int		i;

	tmp = ft_strdup(str);
	i = -1;
	while (tmp[++i])
	{
		while (!(tmp[i] == '\'' || tmp[i] == '\"') && tmp[i])
			i++;
		while ((tmp[i] == '\'' || tmp[i] == '\"') && tmp[i])
			i++;
		while (!(tmp[i] == '\'' || tmp[i] == '\"') && tmp[i])
		{
			if (tmp[i] == ' ')
				tmp[i] = 127;
			i++;
		}
	}
	return (tmp);
}

char	**my_split(char *str)
{
	char	**res;
	int		i;
	int		j;
	char	*tmp;

	tmp = handel_space(str);
	res = ft_split(tmp, ' ');
	i = -1;
	while (res[++i])
	{
		j = -1;
		while (res[i][++j])
			if (res[i][j] == 127)
				res[i][j] = ' ';
	}
	return (free(tmp), res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-oirg <zel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 18:01:02 by zel-oirg          #+#    #+#             */
/*   Updated: 2024/06/20 21:14:19 by zel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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

void	usage(int ac, char **av)
{
	if (ac < 5)
	{
		ft_putstr_fd("usage1: ./pipex_bonus file_in <cmd1>...<cmdn> file_out\n",
			2);
		ft_putstr_fd("usage2: ./pipex_bonus here_doc <lim>  ", 2);
		ft_putstr_fd("<cmd1>...<cmdn> file_out\n", 2);
		exit(1);
	}
	else if (!ft_strncmp(av[1], "here_doc", 8) && ac < 6)
	{
		ft_putstr_fd("usage of here_doc: ./pipex_bonus here_doc", 2);
		ft_putstr_fd("<lim>  <cmd1>...<cmdn> file_out\n", 2);
		ft_putstr_fd("<lim> is the limiter string", 2);
		exit(1);
	}
}

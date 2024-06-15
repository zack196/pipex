/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executing_cmd_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-oirg <zel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 05:29:13 by zel-oirg          #+#    #+#             */
/*   Updated: 2024/06/11 18:21:56 by zel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	error(char *err_msg)
{
	write(2, "bash: ", 6);
	perror(err_msg);
	exit(EXIT_FAILURE);
}

char	**get_env_paths(char **env)
{
	int	i;

	i = -1;
	while (env[++i])
	{
		if (!ft_strncmp(env[i], "PATH", 4))
		{
			env = ft_split(env[i], ':');
			i = -1;
			while (env[++i])
			{
				env[i] = ft_strjoin(env[i], "/");
				if (!env[i])
					return (NULL);
			}
			return (env);
		}
	}
	env[0] = NULL;
	return (env);
}

void	free_double(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		ptr[i] = NULL;
		i++;
	}
	free(ptr);
}

char	*get_cmd_path(char *cmd, char **env)
{
	char	**env_path;
	char	*cmd_path;
	int		i;

	if (ft_strchr(cmd, '/') && !access(cmd, F_OK))
		return (ft_strdup(cmd));
	else if (ft_strchr(cmd, '/') && access(cmd, F_OK))
		return (ft_putstr_fd("bash: ", 2), ft_putstr_fd(cmd, 2),
			ft_putstr_fd(": command not found\n", 2), exit(1), NULL);
	env_path = get_env_paths(env);
	i = -1;
	while (env_path[++i])
	{
		cmd_path = ft_strjoin(env_path[i], cmd);
		if (!access(cmd_path, F_OK))
			return (free_double(env_path), cmd_path);
		free(cmd_path);
	}
	return (ft_putstr_fd("bash: ", 2), ft_putstr_fd(cmd, 2),
		ft_putstr_fd(": command not found\n", 2), exit(1), NULL);
}

void	execute(char *cmd, char **env)
{
	char	**cmd_arg;
	char	*cmd_path;

	cmd_arg = ft_split(cmd, ' ');
	if (!cmd_arg)
		exit(1);
	cmd_path = get_cmd_path(cmd_arg[0], env);
	execve(cmd_path, cmd_arg, env);
	free_double(cmd_arg);
}

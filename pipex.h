/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-oirg <zel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 08:19:11 by zel-oirg          #+#    #+#             */
/*   Updated: 2024/06/20 18:17:54 by zel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stdlib.h>
# include "includes/libft/libft.h"

void	execute(char *cmd, char **env);
void	error(char *err_msg);
void	free_2ptr(char **s);
char	*get_path(char *cmd, char **env);
void	first_child(char *cmd, char *file, int *fd, char **env);
void	second_child(char *cmd, char *file, int *fd, char **env);
char	**my_split(char *str);

#endif
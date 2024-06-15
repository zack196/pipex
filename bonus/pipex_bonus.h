/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-oirg <zel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 08:03:47 by zel-oirg          #+#    #+#             */
/*   Updated: 2024/06/13 19:44:26 by zel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
# include "get_next_line_bonus.h"
# include "../includes/libft/libft.h"

int	here_doc_first(char **av,int ac, char **env);
void	error(char *err_msg);
void	execute(char *cmd, char **env);
void	sp_close(int fd1, int fd2, int fd3);
void	proc(int fd_in, int fd_out, char *cmd, char **env);
char	**my_split(char *str);
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-oirg <zel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 08:03:47 by zel-oirg          #+#    #+#             */
/*   Updated: 2024/06/11 17:12:00 by zel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include "get_next_line_bonus.h"
# include "../includes/libft/libft.h"

void	here_doc_first(char **av, int *fd_pipe, char **env);
void	error(char *err_msg);
void	execute(char *cmd, char **env);
void	sp_close(int fd1, int fd2, int fd3);

#endif

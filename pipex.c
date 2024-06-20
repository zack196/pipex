/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-oirg <zel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 08:05:16 by zel-oirg          #+#    #+#             */
/*   Updated: 2024/06/20 21:22:36 by zel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_child(char *cmd, char *file, int *fd, char **env)
{
	int		file_in;

	file_in = open(file, O_RDONLY, 0777);
	if (file_in == -1)
		error(file);
	if (dup2(file_in, STDIN_FILENO) == -1)
		error("");
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		error("");
	close(fd[1]);
	close(fd[0]);
	close(file_in);
	execute(cmd, env);
}

void	second_child(char *cmd, char *file, int *fd, char **env)
{
	int	file_out;

	file_out = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (file_out == -1)
		error("");
	if (dup2(file_out, STDOUT_FILENO) == -1)
		error("");
	if (dup2(fd[0], STDIN_FILENO) == 1)
		error("");
	close(fd[0]);
	close(fd[1]);
	close(file_out);
	execute(cmd, env);
}

int	main(int ac, char **av, char **env)
{
	int	fd[2];
	int	pid1;
	int	pid2;

	if (ac != 5)
		return (perror("usage: ./pipex <file_in> <cmd1> <cmd2> <file_out>"), 1);
	if (pipe(fd) == -1)
		error("");
	pid1 = fork();
	if (pid1 == -1)
		error("");
	else if (pid1 == 0)
		first_child(av[2], av[1], fd, env);
	pid2 = fork();
	if (pid2 == -1)
		error("");
	else if (pid2 == 0)
		second_child(av[3], av[4], fd, env);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid2, NULL, 0);
	waitpid(pid1, NULL, 0);
}

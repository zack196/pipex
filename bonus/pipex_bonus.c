/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-oirg <zel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 02:34:48 by zel-oirg          #+#    #+#             */
/*   Updated: 2024/06/11 18:38:24 by zel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	proc(int fd_in, int fd_out, char *cmd, char **env)
{
	if (dup2(fd_in, STDIN_FILENO) == -1)
		error("error duppin file_in!");
	if (dup2(fd_out, STDOUT_FILENO) == -1)
		error("error dupping file_out");
	if (fd_in != 0)
		close(fd_in);
	close(fd_out);
	execute(cmd, env);
}

void	first_cmd(char **av, int *fd_pipe, char **env)
{
	int		fd_in;
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		error("error forking");
	if (pid == 0)
	{
		close(fd_pipe[0]);
		fd_in = open(av[1], O_RDONLY, 0777);
		if (fd_in == -1)
			error(av[1]);
		proc(fd_in, fd_pipe[1], av[2], env);
	}
	close(fd_pipe[1]);
}

void	cmd_med(char *cmd, int *pipe_in, char **env)
{
	int		pipe_out[2];
	pid_t	pid;

	if (pipe(pipe_out) == -1)
		error("");
	pid = fork();
	if (pid == -1)
		error("");
	if (pid == 0)
	{
		close(pipe_in[1]);
		close(pipe_out[0]);
		proc(pipe_in[0], pipe_out[1], cmd, env);
	}
	else
	{
		close(pipe_in[0]);
		pipe_in[0] = pipe_out[0];
		pipe_in[1] = pipe_out[1];
	}
}

void	cmd_fin(char **av, int ac, int *pipe_in, char **env)
{
	int		fd_out;
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		error("");
	if (pid == 0)
	{
		if (!ft_strncmp(av[1], "here_doc", 8))
			fd_out = open(av[ac - 1], O_WRONLY | O_CREAT | O_APPEND, 0777);
		else
			fd_out = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
		if (fd_out == -1)
			error("error opening the out_file!");
		close(pipe_in[1]);
		proc(pipe_in[0], fd_out, av[ac - 2], env);
	}
	close(pipe_in[0]);
	close(pipe_in[1]);
	waitpid(pid, NULL, 0);
}
void	f()
{
	system("leaks pipex_bonus");
	system("lsof -c pipex_bonus");
}
int	main(int ac, char **av, char **env)
{
	int	i;
	int	fd_pipe[2];

	atexit(f);
	if (ac < 5)
		return (printf("give me more cmd\n"));
	if (pipe(fd_pipe) == -1)
		error("");
	if (!ft_strncmp(av[1], "here_doc", 8))
	{
		i = 4;
		here_doc_first(av, fd_pipe, env);
	}
	else
	{
		i = 3;
		first_cmd(av, fd_pipe, env);
	}
	while (i < ac - 2)
		cmd_med(av[i++], fd_pipe, env);
	cmd_fin(av, ac, fd_pipe, env);
	while (waitpid(-1, NULL, 0) != -1)
		;
	// while (1);
}

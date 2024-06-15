/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-oirg <zel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 02:34:48 by zel-oirg          #+#    #+#             */
/*   Updated: 2024/06/13 20:27:29 by zel-oirg         ###   ########.fr       */
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

int	first_cmd(char **av, char **env)
{
	int		fd_in;
	int		fd_pipe[2];
	pid_t	pid;

	if (pipe(fd_pipe) == -1)
		error("");
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
		return (0);
	}
	else
	{
		close(fd_pipe[1]);
		return (fd_pipe[0]);
	}
}

int	cmd_med(char *cmd, int pipe_in, char **env)
{
	int	fd_pipe[2];
	pid_t	pid;
	
	if (pipe(fd_pipe) == -1)
		error("");
	pid = fork();
	if (pid == -1)
		error("");
	if (pid == 0)
	{
		close(fd_pipe[0]);
		proc(pipe_in, fd_pipe[1], cmd, env);
		return (0);
	}
	else
	{
		close(fd_pipe[1]);
		close(pipe_in);
		return (fd_pipe[0]);
	}
}



void	cmd_fin(char **av, int ac, int pipe_in, char **env)
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
		proc(pipe_in, fd_out, av[ac - 2], env);
	}
	else
	{
		close(pipe_in);
	}
}
void	f()
{
	// system("leaks pipex_bonus");
	system("lsof -c pipex_bonus");
}
int	main(int ac, char **av, char **env)
{
	int	i;
	int	fd;

	// atexit(f);
	if (ac < 5)
		return (ft_putstr_fd("give me more cmd\n", 1), 1);// -42
	if (!ft_strncmp(av[1], "here_doc", 8))
	{
		i = 4;
		fd = here_doc_first(av, ac, env);
	}
	else
	{
		i = 3;	
		fd = first_cmd(av, env);
	}
	while (i < ac - 2)
		fd = cmd_med(av[i++], fd, env);
	cmd_fin(av, ac, fd, env);
	while ((!ft_strncmp(av[1], "here_doc", 8) && i >= 3)
		|| (ft_strncmp(av[1], "here_doc", 8) && i >= 2))
	{
		wait(NULL);
		i--;
	}
}

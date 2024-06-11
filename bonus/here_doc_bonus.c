/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-oirg <zel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 08:16:05 by zel-oirg          #+#    #+#             */
/*   Updated: 2024/06/11 18:19:44 by zel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*random_f(void)
{
	char	*file_name;
	int		file_len;
	int		fd_rd;
	int		fd_tmp;

	fd_rd = open("/dev/urandom", O_RDONLY, 0777);
	if (fd_rd < 0)
		return (perror("cannot open /dev/urandom"), NULL);
	file_len = 21;
	file_name = malloc((file_len + 1) * sizeof (char));
	if (!file_name)
		return (perror("error malloc faild!"), NULL);
	file_name[0] = '/';
	file_name[1] = 't';
	file_name[2] = 'm';
	file_name[3] = 'p';
	file_name[4] = '/';
	if (read(fd_rd, file_name + 5, 16) == -1)
		error("");
	close(fd_rd);
	file_name[file_len] = 0;
	fd_tmp = open(file_name, O_RDWR | O_CREAT | O_TRUNC, 0777);
	if (fd_tmp < 0)
		return (random_f());
	return (close(fd_tmp), unlink(file_name), file_name);
}

char	*write_in_file(char *lim)
{
	int		fd;
	char	*file_name;
	char	*buff;

	file_name = random_f();
	fd = open(file_name, O_WRONLY | O_CREAT, 0777);
	if (fd == -1)
		error("error opening the random file");
	while (1)
	{
		write(1, "> ", 2);
		buff = get_next_line(0);
		if (!buff || !ft_strcmp(buff, lim))
			break ;
		write(fd, buff, ft_strlen(buff));
		free(buff);
	}
	free(buff);
	close(fd);
	return (file_name);
}

void	here_doc_first(char **av, int *fd_pipe, char **env)
{
	pid_t	pid;
	int		fd;
	char	*file;

	pid = fork();
	if (pid == -1)
		error("error forking");
	if (pid == 0)
	{
		close(fd_pipe[0]);
		file = write_in_file(av[2]);
		fd = open(file, O_RDONLY, 0777);
		if (fd == -1)
			error("error openning file! ");
		if (dup2(fd, STDIN_FILENO) == -1)
			error("error dupping tmp_file");
		if (dup2(fd_pipe[1], STDOUT_FILENO) == -1)
			error("error duping pipe file 1!");
		close(fd_pipe[1]);
		execute(av[3], env);
	}
	close(fd_pipe[1]);
	waitpid(pid, NULL, 0);
	unlink(file);
}

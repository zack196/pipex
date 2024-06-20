/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-oirg <zel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 08:16:05 by zel-oirg          #+#    #+#             */
/*   Updated: 2024/06/20 20:01:48 by zel-oirg         ###   ########.fr       */
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
		return (free(file_name), random_f());
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

int	here_doc_first(char **av, char **env)
{
	pid_t	pid;
	int		fd;
	int		fd_pipe[2];
	char	*file;

	if (pipe(fd_pipe) == -1)
		error("");
	file = write_in_file(av[2]);
	pid = fork();
	if (pid == -1)
		error("error forking");
	if (pid == 0)
	{
		close(fd_pipe[0]);
		fd = open(file, O_RDONLY, 0777);
		if (fd == -1)
			error("error openning file! ");
		unlink(file);
		proc(fd, fd_pipe[1], av[3], env);
		return (0);
	}
	return (free(file), close(fd_pipe[1]), fd_pipe[0]);
}

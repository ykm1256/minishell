/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 22:43:34 by kyoon             #+#    #+#             */
/*   Updated: 2022/08/19 14:04:25 by kyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_redirect.h"
#include "../ft_sig/ft_sig.h"

int	ft_gt(char *path, int offset)
{
	int	fd;

	if (offset)
		fd = open(path, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		return (1);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	return (0);
}

int	ft_lt(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (1);
	dup2(fd, STDIN_FILENO);
	close(fd);
	return (0);
}

static int	ft_dupin(void)
{
	int	fd;

	fd = open(HEREDOC, O_RDONLY);
	if (fd < 0)
		return (1);
	dup2(fd, STDIN_FILENO);
	close(fd);
	return (0);
}

static void	ft_child(char *end, int fd)
{
	char	*str;

	ft_set_child(3);
	while (1)
	{
		str = readline(">");
		if (!str || !ft_strncmp(str, end, ft_strlen(str) + 1))
			break ;
		write(fd, str, ft_strlen(str));
		write(fd, "\n", 1);
		free(str);
	}
	exit(0);
}

int	ft_dlt(char *end, t_info *info)
{
	pid_t	pid;
	int		fd;

	ft_set_child(0);
	pid = fork();
	fd = open(HEREDOC, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		return (1);
	if (pid == 0)
		ft_child(end, fd);
	close(fd);
	wait(&fd);
	ft_set_child(2);
	ft_set_term(info);
	if (WIFSIGNALED(fd))
	{
		write(1, "\n", 1);
		ft_dupin();
		return (128 + WTERMSIG(fd));
	}
	return (ft_dupin());
}

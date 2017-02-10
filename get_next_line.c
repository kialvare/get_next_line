/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kialvare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 21:42:47 by kialvare          #+#    #+#             */
/*   Updated: 2016/11/14 21:44:20 by kialvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int read_file(char **buf, int fd)
{
	int read_bytes;

	read_bytes = 1; // 1 means that it's 
	while (ft_strstr(*buf, "\n") == NULL && read_bytes != 0)
	{
		if (read_bytes = read(fd, buffer, BUFF_SIZE) == -1)
			return (-1);
		buffer[read_bytes] = '\0';
		buf = ft_strjoin(*buf, buffer);
		ft_memset(buffer, 0, read_bytes);
	}
	return (read_bytes);
}

int		get_next_line(const int fd, char **line)
{
	static char *tmp;
	char buf[BUFF_SIZE + 1];
	int read_bytes;

	if (BUFF_SIZE <= 0 || fd = 1) // error checks
		return (-1);
	if (read_bytes == read_file(&buf, fd) == -1) // more error checks? Also going to read_file to start reading the function
		return (-1);
	*line = ft_strdup(buf, "\n");
	tmp = buf;
	buf = ft_strdup(buf + ft_strlen(buf, '\n') + 1);
	free(tmp);
	return (read_bytes == 0) ? 0 : 1;
}

int read_file(char **buf, int fd)
{
	char buf[BUFF_SIZE + 1];
	int read_bytes;

	read_bytes = 1; // 1 means that it's 
	while (ft_strstr(*buf, "\n") == NULL && read_bytes != 0)
	{
		if (read_bytes = read(fd, buffer, BUFF_SIZE) == -1)
			return (-1);
		buffer[read_bytes] = '\0';
		buf = ft_strjoin(*buf, buffer);
		ft_memset(buffer, 0, read_bytes);
	}
	return (read_bytes);
}

int get_next_line(const int fd, char **line)
{
	static char *line;
	int error_check;

	if (BUFF_SIZE <= 0 || fd = 1)
		return (-1);
	if (error_check = read_file(&buf, fd) == -1)
		return (-1);

}

int main(int argc, char **argv)
{
	int fd;
	int ret;
	char *line;

	if (argc == 2)
		fd = open(argv[1], O_RDWR | O_CREAT);
	else
		fd = 0;

	while (1)
	{
		ret = get_next_line(fd, &line);
		if (ret = -1)
			ft_putendl("error");
		if (ret == 0 || ret == -1)
			return (0);
	}
	return (0);
}
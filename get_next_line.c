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

static int  split(int const fd, char *buff, char *store[fd])
{
    char    *tmp;
    char    *p;
    int     i;

    i = 0;
    while (!(p = ft_strchr(store[fd], '\n')) &&
        (i = read(fd, buff, BUFF_SIZE)) > 0)
    {
        buff[i] = '\0';
        tmp = store[fd];
        store[fd] = ft_strjoin(tmp, buff);
        ft_strdel(&tmp);
    }
    if (i == -1)
        return (-1);
    if (i == 0 && !p)
        return (0);
    return (1);
}

int         get_next_line(int const fd, char **line)
{
    static char *store[256];
    char        *tmp;
    int         ret;
    char        buff[BUFF_SIZE + 1];

    if (fd < 0 || !line)
        return (-1);
    if (!store[fd])
        store[fd] = ft_strnew(1);
    ret = split(fd, buff, &*store);
    if (ret == 0)
    {
        *line = store[fd];
        store[fd] = NULL;
        return (0);
    }
    *line = ft_strsub(store[fd], 0, ft_strchr(store[fd], '\n') - store[fd]);
    tmp = store[fd];
    store[fd] = ft_strdup(ft_strchr(store[fd], '\n') + 1);
    ft_strdel(&tmp);
    return (1);
}

int main(int argc, char **argv)
{
    int fd;
    int ret;
    char *line;

    if (argc == 2)
        fd = open(argv[1], O_RDONLY);
    else
    {
        fd = 0;
        return (0);
    }

    int i;

    i = 0;
    while (1)
    {
        ret = get_next_line(fd, &line);
        printf("%d\n", i);
        printf("%s\n", line);
        if (ret == 0 || ret == -1)
            return (0);
        i++;
    }
    return (0);
}
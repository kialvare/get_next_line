/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kialvare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 21:42:58 by kialvare          #+#    #+#             */
/*   Updated: 2016/11/14 21:43:01 by kialvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H
# define BUFF_SIZE 32
# define MAX_SIZE 100000 // <--- Research more on max buffer size/buffer sizes

# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h> // <---- Supprimez ceci à la fin

int		get_next_line(const int fd, char **line);

#endif

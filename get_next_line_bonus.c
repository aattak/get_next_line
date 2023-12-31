/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aattak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 11:47:24 by aattak            #+#    #+#             */
/*   Updated: 2023/12/31 14:12:44 by aattak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	int			nl;
	ssize_t		r_len;
	char		*line;
	static char	buffer[OPEN_MAX][BUFFER_SIZE + 1] = {""};

	if (fd < 0)
		return (NULL);
	line = NULL;
	nl = 0;
	r_len = 1;
	while (r_len)
	{
		if (buffer[fd][0])
			line = ft_get_line(line, buffer[fd], &nl);
		if (nl)
			return (line);
		r_len = read(fd, buffer[fd], BUFFER_SIZE);
		if (r_len == -1)
			return (free(line), NULL);
		buffer[fd][r_len] = '\0';
	}
	return (line);
}

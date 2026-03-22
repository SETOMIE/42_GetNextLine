/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyeo <asyeo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 05:09:36 by asyeo             #+#    #+#             */
/*   Updated: 2026/03/22 15:44:25 by asyeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_get_line(char **prev)
{
	size_t	i;
	char	*tmp;
	char	*res;

	i = 0;
	if (!*prev || !(**prev))
		return (free(*prev), *prev = NULL, NULL);
	while ((*prev)[i] && (*prev)[i] != '\n')
		i++;
	res = malloc(i + 1 + ((*prev)[i] == '\n'));
	if (!res)
		return (NULL);
	i = 0;
	while ((*prev)[i] && (*prev)[i] != '\n')
	{
		res[i] = (*prev)[i];
		i++;
	}
	if ((*prev)[i] == '\n')
		res[i++] = '\n';
	res[i] = '\0';
	tmp = ft_strdup_gnl(*prev + i);
	free(*prev);
	*prev = tmp;
	return (res);
}

char	*get_next_line(ssize_t fd)
{
	size_t		i;
	ssize_t		bytes;
	char		*buffer;
	static char	*prev[MAX_FD];

	if (fd < 0 || fd >= MAX_FD || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes = 1;
	while (bytes)
	{
		i = -1;
		while (prev[fd] && prev[fd][++i])
			if (prev[fd][i] == '\n')
				return (free(buffer), ft_get_line(&prev[fd]));
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
			return (free(buffer), NULL);
		buffer[bytes] = '\0';
		prev[fd] = ft_strjoin_gnl(prev[fd], buffer, bytes);
	}
	return (free(buffer), ft_get_line(&prev[fd]));
}

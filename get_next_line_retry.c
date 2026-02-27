/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_retry.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyeo <asyeo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 14:12:46 by asyeo             #+#    #+#             */
/*   Updated: 2026/02/27 13:04:18 by asyeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"

char	*ft_append_storage()
char	*ft_read_line()
char	*ft_extract_line()
char	*ft_free_buffer()
char	*get_next_line(int fd)
{
	static char *storage;
	char        *line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	storage = read_storage(storage, fd);
	if (!storage)
		return (NULL);
	line = extract_line(&storage);
	if (storage && *storage == '\0')
	{
		free(storage);
		storage = NULL;
	}
	return (line);
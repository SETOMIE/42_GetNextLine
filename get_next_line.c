/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyeo <asyeo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 14:12:45 by asyeo             #+#    #+#             */
/*   Updated: 2026/02/27 11:56:02 by asyeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#define BUFFER_SIZE 1024 

char	*read_storage(char *storage, int fd)
{
	char	*buffer;
	char	*joined;
	ssize_t	bytes_read;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = 1; //initialize loop entry.
	while (bytes_read > 0) //read until EOF or '\n'.
	{
		if (storage && ft_strchr(storage, '\n'))
			break;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buffer);
			free(storage);
			return (NULL);
		}
		buffer[bytes_read] = '\0'; //null-terminate buffer.
		joined = ft_strjoin(storage, buffer); //append new data to storage.
		free(storage);
		storage = joined;
		if (!storage)
		{
			free(buffer);
			return (NULL);
		}
	}
	free(buffer); //free temp buffer.
	return (storage); //return updated storage w/ appended data.
}

char    *extract_line(char **storage)
{
	char    *line;
	char    *temp;
	size_t  i = 0;
	size_t  len;

	if (!*storage || !**storage)
		return (NULL);
	while ((*storage)[i] && (*storage)[i] != '\n')
		i++;
	if ((*storage)[i] == '\n')
		len = i + 1; //include newline.
	else
		len = i; //no newline.
	line = ft_substr(*storage, 0, len); // extract line from storage.
	temp = ft_strdup(*storage + len); // dup remaining storage after line.
	if (!line || !temp)
	{
		free(line);
		free(storage);
		free(temp);
		return (NULL);
	}
	free(*storage); // free old storage.
	*storage = temp;
	return (line);
}
// (!*storage || !**storage) will check if storage is NULL or empty, 
// if so return NULL to indicate no more lines to read. Important for EOF handling.

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
}

	// if (*storage == '\0')
	// {
	//     free(storage);
	//     storage = NULL;
	//     return (NULL);
	// }

	// This chunk will check if the storage is empty; if it is, then it frees the storage then returns NULL. 
	// This (very importantly) prevents memory leaks and ensures the function behaves correctly when there are no more readable lines.
	// If you have [ if (!*storage || !**(storage)); ] in *extract_line then including it again is unnecessarily redudant.
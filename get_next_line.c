/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyeo <asyeo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 14:12:45 by asyeo             #+#    #+#             */
/*   Updated: 2026/01/29 14:21:14 by asyeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *read_storage(char *storage, int fd)

char    *extract_line(char **storage)

char	*get_next_line(int fd)
{
    static char *stash;
    char        *temp;
    int         i;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    storage = read_into_storage(fd, storage);
    if (!storage)
        return (NULL);
    return (extract_line(&storage));
}
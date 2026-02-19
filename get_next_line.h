/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyeo <asyeo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 14:12:40 by asyeo             #+#    #+#             */
/*   Updated: 2026/01/29 14:20:09 by asyeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#   define BUFFER_SIZE 42
# endif

/* gnl */

char	*get_next_line(int fd)
char    *fill_line_buffer(int fd, char *left_c, char *buffer)
char    *set_line(char *line_buffer)

/* utils */

size_t	ft_strlen(const char *str)
char	*ft_strchr(const char *s, int c)
char	*ft_strjoin(char const *s1, char const *s2)
char	*ft_strdup(const char *s)
char	*ft_substr(char const *s, unsigned int start, size_t len)

#endif

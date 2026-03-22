/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyeo <asyeo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 05:09:36 by asyeo             #+#    #+#             */
/*   Updated: 2026/03/22 15:54:27 by asyeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 67
# endif

# define MAX_FD 1024

char	*get_next_line(ssize_t fd);
char	*ft_strjoin_gnl(char *prev, char *buffer, ssize_t bytes);
char	*ft_get_line(char **prev);
char	*ft_strdup_gnl(char *s);

#endif

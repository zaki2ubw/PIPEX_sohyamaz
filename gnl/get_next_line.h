/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 20:58:50 by sohyamaz          #+#    #+#             */
/*   Updated: 2024/12/30 15:25:14 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stddef.h>
# include <stdio.h>
# include <limits.h>
# include <stdlib.h>
# include <stdint.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 512
# endif

char	*gnl_strjoin(char *s1, char c);
void	*gnl_calloc(size_t nmemb, size_t size);
size_t	gnl_strlen(char *s);
void	gnl_bzero(void *s, size_t n);
int		get_next_char(int fd);
char	*set_next_line(int c, char *val);
char	*get_next_line(int fd);

#endif

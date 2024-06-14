/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgriffit <rgriffit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:31:56 by rgriffit          #+#    #+#             */
/*   Updated: 2024/05/31 15:48:48 by rgriffit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

// To use for the use of variable size_t, NULL pointer, *malloc(), free()
// *malloc() prototype - void *malloc(size_t size);
// free() prototype - void free(void *ptr);
# include <stdlib.h>
// To use size_t, ssize_t, write(), read(),
// write() prototype -  ssize_t      write(int, const void *, size_t);
// read() prototype -  ssize_t      read(int, void *, size_t);
# include <unistd.h>
// #include <fcntl.h> - file control library 

// This is a good way of setting the buffer size to a default for your files
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif
// to re-define it in particular files use above your includes - #define BUFFER_SIZE 24

// Prototypes used in get_next_line.c
// added to utils.c - taken from my libft, delete if not used 
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *str);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);

char	*get_next_line(int fd);


#endif

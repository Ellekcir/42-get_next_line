/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgriffit <rgriffit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:54:56 by rgriffit          #+#    #+#             */
/*   Updated: 2024/05/31 16:55:03 by rgriffit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Finnds the first occurance of a character in a string
char	*ft_strchr(const char *s, int c)
{
	char	*str;
	char	chr;
	int		i;

	chr = (char)c;
	str = (char *)s;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == chr)
			return (&str[i]);
		i++;
	}
    if (chr == '\0')
	    return (&str[i]);
    return (NULL);
}

// gives the length of string
size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

// Duplicates a string
char	*ft_strdup(const char *str)
{
	size_t	len;
	char	*dup;
	size_t	i;

	len = ft_strlen(str);
	dup = (char *)malloc(sizeof(char) * len + 1);
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

// Extracts a string from a string
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*sub;
	size_t		sublen;
	size_t		i;

	sublen = ft_strlen(s);
	if (start > sublen)
		len = 0;
	if (len > (sublen - start))
		len = sublen - start;
	sub = (char *)malloc(sizeof(char) * len + 1);
	if (sub == NULL || s == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

// Joins two strings
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		i;
	int		j;

	i = 0;
	j = 0;
	result = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (result == NULL || !s1 || !s2)
		return (NULL);
	while (s1[i] != '\0')
	{
		result[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		result[i + j] = s2[j];
		j++;
	}
	result[i + j] = '\0';
	return (result);
}

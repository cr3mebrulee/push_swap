/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:49:23 by psulzyck          #+#    #+#             */
/*   Updated: 2024/02/12 15:39:11 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*read_line function read file till the \n character, store it in buf 
and concatenate with the string stored in the static variable 
written in previous call. Why we dont free buf: read 
system call does not append data to the buffer; 
instead, it overwrites the existing content of the buffer 
with the newly read data.*/

static char	*read_line(int fd, char *buf, char *backup)
{
	ssize_t		i;
	char		*char_temp;

	i = 1;
	while (i > 0)
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i == -1)
			return (0);
		else if (i == 0)
			break ;
		buf[i] = '\0';
		if (backup == NULL)
		{
			backup = ft_strdup("");
		}
		char_temp = backup;
		backup = ft_strjoin(char_temp, buf);
		free(char_temp);
		char_temp = NULL;
		if (ft_strchr (buf, '\n'))
			break ;
	}
	return (backup);
}

/*extract function extract the substring from the string
returned by read_line function. it statrs extraction from 
the next to the \n character (count + 1) and goes
till the end of thistring*/

static char	*extract(char *line)
{
	size_t	count;
	char	*rest;

	count = 0;
	while (line[count] != '\n' && line[count] != '\0')
		count++;
	if (line[count] == '\0' || line[1] == '\0')
		return (0);
	rest = ft_substr(line, count + 1, ft_strlen(line) - count);
	if (rest == NULL || *rest == '\0')
	{
		free(rest);
		rest = NULL;
	}
	line[count + 1] = '\0';
	return (rest);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buf;
	static char	*backup;

	if (fd == -1 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(backup);
		backup = NULL;
		return (0);
	}
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	line = read_line(fd, buf, backup);
	free(buf);
	buf = NULL;
	if (!line)
	{
		backup = NULL;
		return (NULL);
	}
	backup = extract(line);
	return (line);
}

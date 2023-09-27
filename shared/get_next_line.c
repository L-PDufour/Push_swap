/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldufour <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 08:33:27 by ldufour           #+#    #+#             */
/*   Updated: 2023/06/06 09:24:19 by ldufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static char	*extract_line(char *str)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!str[0])
		return (NULL);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (ft_free(&line));
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		line[j++] = str[i++];
	if (str[i] == '\n')
		line[j++] = str[i++];
	line[j] = '\0';
	return (line);
}

static char	*fill_stash(char *stash, int fd)
{
	char	*buffer;
	int		read_bytes;

	read_bytes = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (ft_free(&stash));
	buffer[0] = '\0';
	while (read_bytes > 0 && !ft_strchr(buffer, '\n'))
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes > 0)
		{
			buffer[read_bytes] = '\0';
			stash = ft_strjoin(stash, buffer);
		}
	}
	free(buffer);
	if (read_bytes == -1)
		return (ft_free(&stash));
	return (stash);
}

static char	*clean_stash(char *str)
{
	int		i;
	int		j;
	char	*new_stash;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i] || (str[i] == '\n' && !str[i + 1]))
		return (ft_free(&str));
	new_stash = malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!new_stash)
		return (ft_free(&str));
	i++;
	j = 0;
	while (str[i])
		new_stash[j++] = str[i++];
	new_stash[j] = '\0';
	free(str);
	return (new_stash);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash;

	stash = NULL;
	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = fill_stash(stash, fd);
	if (!stash)
		return (NULL);
	line = extract_line(stash);
	if (!line)
		return (ft_free(&stash));
	stash = clean_stash(stash);
	return (line);
}

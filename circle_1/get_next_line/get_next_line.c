/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabalqu <mjabalqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 10:36:23 by marcos            #+#    #+#             */
/*   Updated: 2025/12/16 20:20:18 by mjabalqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*manage_backup(char **backup)
{
	char	*line;

	if (ft_strlen(*backup) > 0)
	{
		line = *backup;
		*backup = NULL;
	}
	else
	{
		free(*backup);
		*backup = NULL;
		return (NULL);
	}
	return (line);
}

static char	*extract_line(char **buffer, char **pos, char **backup)
{
	char	*line;
	char	*temp;

	line = ft_substr(*backup, 0, (size_t)(*pos - *backup + 1));
	if (!line)
		return (free(*buffer), NULL);
	temp = ft_substr(*backup, (unsigned int)(*pos - *backup + 1),
			ft_strlen(*pos + 1));
	if (!temp)
	{
		free(line);
		free(*buffer);
		return (NULL);
	}
	free(*backup);
	*backup = temp;
	free (*buffer);
	*buffer = NULL;
	return (line);
}

static int	read_file(int fd, char **buffer, char **backup)
{
	int	bytes_read;

	bytes_read = read(fd, *buffer, BUFFER_SIZE);
	if (bytes_read > 0)
	{
		(*buffer)[bytes_read] = '\0';
		*backup = ft_strjoin(*backup, *buffer);
		if (!*backup)
		{
			free(*buffer);
			return (-1);
		}
	}
	else
	{
		free(*buffer);
		*buffer = NULL;
	}
	return (bytes_read);
}

static char	*get_the_line(char **backup, char **pos, int fd, char **buffer)
{
	ssize_t	bytes_read;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		if (*backup != NULL)
			*pos = ft_strchr(*backup, '\n');
		if (*pos != NULL)
			return (extract_line(buffer, pos, backup));
		bytes_read = read_file(fd, buffer, backup);
		if (bytes_read == -1)
			return (free(*backup), *backup = NULL, NULL);
	}
	if (*backup)
		return (manage_backup(backup));
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char		*backup[1024];
	char			*buffer;
	char			*line;
	char			*pos;

	pos = NULL;
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer || fd < 0 || BUFFER_SIZE <= 0)
		return (free(buffer), NULL);
	line = get_the_line(&backup[fd], &pos, fd, &buffer);
	return (line);
}

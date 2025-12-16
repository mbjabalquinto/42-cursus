/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabalqu <mjabalqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 10:36:23 by marcos            #+#    #+#             */
/*   Updated: 2025/12/16 12:35:21 by mjabalqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*manage_backup(char **backup)
{
	char	*final_string;

	if (ft_strlen(*backup) > 0)
	{
		final_string = *backup;
		*backup = NULL;
	}
	else
	{
		free(*backup);
		*backup = NULL;
		return (NULL);
	}
	return (final_string);
}

static char	*extract_line(char **buffer, char *pos, char **backup)
{
	char	*final_string;

	final_string = ft_substr(*backup, 0, (size_t)(pos - *backup + 1));
	if (!final_string)
		return (NULL);
	free (*buffer);
	*buffer = NULL;
	*buffer = ft_substr(*backup, (unsigned int)(pos - *backup + 1),
			ft_strlen(pos + 1));
	if (*buffer)
	{
		free(*backup);
		*backup = *buffer;
	}
	else
		return (NULL);
	return (final_string);
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

char	*get_next_line(int fd)
{
	static char		*backup[1024];
	char			*buffer;
	char			*final_string;
	char			*pos;
	int				bytes_read;

	pos = NULL;
	final_string = NULL;
	buffer = NULL;
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer || fd < 0 || BUFFER_SIZE <= 0)
		return (free(buffer), NULL);
	bytes_read = read_file(fd, &buffer, &backup[fd]);
	while (pos == NULL && bytes_read > 0)
	{
		pos = ft_strchr(backup[fd], '\n');
		if (pos != NULL)
			final_string = extract_line(&buffer, pos, &backup[fd]);
		else
			bytes_read = read_file(fd, &buffer, &backup[fd]);
	}
	if (bytes_read == -1 || !(backup[fd]))
		return (NULL);
	if (pos == NULL && bytes_read == 0 && final_string == NULL
		&& backup[fd] != NULL)
		final_string = manage_backup(&backup[fd]);
	return (final_string);
}

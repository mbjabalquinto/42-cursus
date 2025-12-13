/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabalqu <mjabalqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 10:36:23 by marcos            #+#    #+#             */
/*   Updated: 2025/12/13 15:48:27 by mjabalqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer || fd < 0)
		return (NULL);
	bytes_read = read_file(fd, &buffer, &backup[fd]);
	while (pos == NULL && bytes_read > 0)
	{
		pos = ft_strchr(backup[fd], '\n');
		if (pos != NULL)
		{
			final_string = ft_substr(backup[fd], 0, (size_t)(pos - backup[fd] + 1));
			free (buffer);
			buffer = ft_substr(backup[fd], (unsigned int)(pos - backup[fd]) + 1, ft_strlen(pos + 1));
			if (buffer)
			{
				free(backup[fd]);
				backup[fd] = buffer;
			}
		}
		else
			bytes_read = read_file(fd, &buffer, &backup[fd]);
	}
	if (bytes_read == -1 || !(final_string) || !(backup[fd]))
		return (NULL);
	if (pos == NULL && bytes_read == 0 && final_string == NULL && backup[fd] != NULL)
	{
		if (ft_strlen(backup[fd]) > 0)
		{
			final_string = backup[fd];
			backup[fd] = NULL;
		}
		else
		{
			free(backup[fd]);
			backup[fd] = NULL;
			return (NULL);
		}
	}
	return (final_string);
}
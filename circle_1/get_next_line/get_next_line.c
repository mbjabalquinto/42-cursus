/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabalqu <mjabalqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 10:36:23 by marcos            #+#    #+#             */
/*   Updated: 2025/12/16 18:37:24 by mjabalqu         ###   ########.fr       */
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

static char	*extract_line(char **buffer, char *pos, char **backup)
{
	char	*line;
	char	*temp;

	line = ft_substr(*backup, 0, (size_t)(pos - *backup + 1));
	if (!line)
		return (free(*buffer), NULL);
	temp = ft_substr(*backup, (unsigned int)(pos - *backup + 1),// HAGO EL LEN DE POS + 1 PARA QUE NO CUENTE EL SALTO DE LINEA.
			ft_strlen(pos + 1));
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

char	*get_next_line(int fd)
{
	static char		*backup[1024];
	char			*buffer;
	char			*line;
	char			*pos;
	int				bytes_read;

	line = NULL;
	pos = NULL;
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer || fd < 0 || BUFFER_SIZE <= 0)
		return (free(buffer), NULL);
	bytes_read = 1;
	while (bytes_read > 0) 
	{
		if (backup[fd] != NULL)
			pos = ft_strchr(backup[fd], '\n');
		if (pos != NULL)
			return (line = extract_line(&buffer, pos, &backup[fd]));
		else
			bytes_read = read_file(fd, &buffer, &backup[fd]);
	}
	if (bytes_read == -1)
	{	
		if (backup[fd] != NULL)
		{
			free(backup[fd]);
			backup[fd] = NULL;
		}
		return (NULL);
	}
	if (pos == NULL && bytes_read == 0 && line == NULL
		&& backup[fd] != NULL)
		line = manage_backup(&backup[fd]);
	return (line);
}

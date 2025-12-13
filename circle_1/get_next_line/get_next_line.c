/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabalqu <mjabalqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 10:36:23 by marcos            #+#    #+#             */
/*   Updated: 2025/12/13 10:31:17 by mjabalqu         ###   ########.fr       */
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
	char			*pos;
	int				bytes_read;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer || fd < 0)
		return (NULL);
	bytes_read = read_file(fd, &buffer, &backup[fd]);
	
	pos = ft_strchr(backup[fd], '\n');

}
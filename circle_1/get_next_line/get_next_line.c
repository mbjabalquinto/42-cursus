/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabalqu <mjabalqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 10:36:23 by marcos            #+#    #+#             */
/*   Updated: 2025/12/12 10:30:04 by mjabalqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		*backup[1024];
	char			*buffer;
	char			*pos;
	int				bytes_read;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer || fd < 0)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		backup[fd] = ft_strjoin(backup[fd], buffer);
		if (!backup[fd])
		{
			free(buffer);
			return (NULL);
		}
		pos = ft_strchr(backup[fd], '\n');
	}
	else
		return (NULL);
	

}
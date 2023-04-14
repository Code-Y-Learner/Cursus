/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjyu <seungjyu@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:38:00 by seungjyu          #+#    #+#             */
/*   Updated: 2023/04/11 18:40:00 by seungjyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char	*get_buf(int fd, char *str)
{
	int		read_size;
	char	buf[BUFFER_SIZE + 1];

	read_size = 1;
	while (read_size != 0 && !ft_strchr(buf, '\n'))
	{
		read_size = read(fd, buf, BUFFER_SIZE);
		buf[read_size] = '\0';
		str = ft_strjoin_expand(str, buf);
	}
	if (read_size == -1)
		return (0);
	return (str);
}

char	*check_line(char *str)
{
	char	*line;
	size_t	i;

	i = 0;
	if (str[i] == '\0')
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 1));
	line = ft_memmove(line, str, i);
	if (!line)
		return (0);
	if (str[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	// str = check_line2(str);
	return (line);
}

// char	*check_line2(char *str)
// {
// 	char	*tmp;
// 	int	i;

// 	i = 0;
// 	while (str[i] && str[i] != '\n')
// 		i++;
// 	tmp = (char *)malloc()
// 	if (ft_strchr(str, '\n'))

// }

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	str = 0;
	if (fd < 1 || BUFFER_SIZE < 1)
		return (0);
	str = get_buf(fd, str);
	if (!str)
		return (0);
	line = check_line(str);
	return (line);
}

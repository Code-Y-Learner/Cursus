/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjyu <seungjyu@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:52:26 by seungjyu          #+#    #+#             */
/*   Updated: 2023/04/17 15:52:26 by seungjyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <unistd.h>

char	*check_line2(char *str);
char	*get_buf(int fd, char *str);
char	*ft_strjoin_expand(char *s1, char const *s2);
char	*check_line(char *str);
char	*get_next_line(int fd);

char	*check_line(char *str)
{
	char	*line;
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	if (str[i] == '\0')
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	line = (char *)malloc(i + 1);
	if (!line)
		return (0);
	line = ft_memmove(line, str, i);
	line[i] = '\0';
	return (line);
}

char	*check_line2(char *str)
{
	char	*tmp;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(str);
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i] || !str[i + 1])
		return (ft_clear(&str));
	tmp = (char *)malloc(len - i);
	if (!tmp)
		return (ft_clear(&str));
	ft_bzero(tmp, len - i);
	if (str[i] == '\n')
		i++;
	ft_memmove(tmp, &str[i], len - i);
	tmp[len - i] = '\0';
	ft_clear(&str);
	return (tmp);
}

char	*ft_strjoin_expand(char *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*str;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (!s1)
	{
		s1 = (char *)malloc(1);
		if (!s1)
			return (0);
		ft_bzero(s1, 1);
	}
	str = (char *)malloc(len_s1 + len_s2 + 1);
	if (!str)
		return (ft_clear(&s1));
	ft_bzero(str, len_s1 + len_s2 + 1);
	ft_memmove(str, s1, len_s1);
	ft_memmove(str + len_s1, s2, len_s2);
	free(s1);
	return (str);
}

char	*get_buf(int fd, char *str)
{
	int		read_size;
	char	*buf;

	read_size = 1;
	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (ft_clear(&str));
	ft_bzero(buf, BUFFER_SIZE + 1);
	while (read_size != 0 && !ft_strchr(buf, '\n'))
	{
		read_size = read(fd, buf, BUFFER_SIZE);
		if (read_size == -1)
		{
			free(buf);
			free(str);
			return (0);
		}
		buf[read_size] = '\0';
		str = ft_strjoin_expand(str, buf);
	}
	free(buf);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1 || fd >= OPEN_MAX)
		return (0);
	str[fd] = get_buf(fd, str[fd]);
	if (!str[fd])
		return (0);
	line = check_line(str[fd]);
	if (!line)
		return (ft_clear(&str[fd]));
	str[fd] = check_line2(str[fd]);
	return (line);
}

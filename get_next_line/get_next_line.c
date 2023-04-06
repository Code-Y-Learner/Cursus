/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjyu <seungjyu@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:38:00 by seungjyu          #+#    #+#             */
/*   Updated: 2023/04/06 21:27:50 by seungjyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

#define BUFFER_SIZE 1


void	strslice(char *str, int c)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(str);
	while (str[i])
	{
		if (str[i] = c)
			str[i] = '\0';
		i++;
	}
	while (i < len)
	{
		str[i] = 0;
		i++;
	}
}

ssize_t	check(char *str, const char *buf, int readsize) // 개행 체크 eol 체크 str 체크 str에 이어붙이기
{
	if (!readsize)
		return (0);
	
	strslice(buf, "\n");
	if (!str)
		str = ft_strdup(dup);
	else
	{
		
	}
}

char	*get_next_line(int fd)
{
	int			readsize;
	static char	*str;
	char		buf[BUFFER_SIZE + 1];

	if (fd < 1)
		return (0);
	readsize = read(fd, buf, BUFFER_SIZE);
	buf[BUFFER_SIZE] = '\0';
	if (readsize < 0)
		return (0);
	check(str, buf);

}

int	main(void)
{
	int			fd;
	int			read_size;
	static char	*str;
	char		buf[BUFFER_SIZE + 1];

	fd = open("test.txt", O_RDONLY);
	str = 0;
	read_size = 1;
	if (fd < 1)
	{
		printf("open error\n");
		return (0);
	}
	else
	{
		while (read_size)
		{
			read_size = read(fd, buf, BUFFER_SIZE);
			buf[read_size] = '\0';
			if (str == 0)
				str = ft_strdup(buf);
			else
				ft_strcat(str, buf);
			if (strchr(str, '\n'))
				return (0);
		}
		close(fd);
	}
	printf("%s\n", str);
	free(str);
	return (0);
}

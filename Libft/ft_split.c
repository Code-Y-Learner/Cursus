/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjyu <seungjyu@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 12:38:04 by seungjyu          #+#    #+#             */
/*   Updated: 2023/04/02 20:51:36 by seungjyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char		**ft_split(char const *s, char c);
static int	wc(char const *str, char c);
static int	ft_clear(char **words);
static int	fs(char const *str, char sep, char **words, int *a);

static int	check(char c, char sep)
{
	if (!sep)
		return (0);
	if (c == sep)
		return (1);
	return (0);
}

static int	ft_clear(char **words)
{
	int	i;

	i = 0;
	while (words[i])
	{
		free(words[i]);
		i++;
	}
	free(words);
	return (0);
}

static int	fs(char const *str, char sep, char **words, int *a)
{
	int		i;
	char	*answer;

	i = 0;
	answer = (char *)malloc(sizeof(char) * (a[1] + 1));
	if (!answer)
	{
		words[a[0] - 1] = answer;
		ft_clear(words);
		return (0);
	}
	while (str[i] && !check(str[i], sep))
	{
		answer[i] = str[i];
		i++;
	}
	answer[i] = '\0';
	words[a[0] - 1] = answer;
	words[a[0]] = 0;
	return (1);
}

static int	wc(char const *str, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		while (str[i] && check(str[i], c))
			i++;
		if (str[i] && !check(str[i], c))
		{
			j++;
			while (str[i] && !check(str[i], c))
				i++;
		}
	}
	return (j);
}

char	**ft_split(char const *s, char c)
{
	int		a[2];
	char	**answer;

	a[0] = 0;
	answer = (char **)malloc(sizeof(char *) * (wc((char *)s, c) + 1));
	if (!answer)
		return (0);
	while (*s != '\0')
	{
		while (*s && check(*s, c))
			s++;
		if (*s && !check(*s, c))
		{
			a[0]++;
			a[1] = 0;
			while (*(s + a[1]) && !check(*(s + a[1]), c))
				a[1]++;
			if (fs(s, c, answer, a) == 0)
				return (0);
			s += a[1];
		}
	}
	answer[a[0]] = 0;
	return (answer);
}

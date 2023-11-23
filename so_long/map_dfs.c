/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_dfs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjyu <seungjyu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 16:23:43 by seungjyu          #+#    #+#             */
/*   Updated: 2023/11/17 17:15:16 by seungjyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_visited(int **visited, int hei)
{
	int	i;

	i = 0;
	while (i < hei - 1)
	{
		free(visited[i]);
		visited[i] = 0;
		i++;
	}
	free(visited);
	visited = 0;
}

int	**visited_init(t_game *game)
{
	int	**visited;
	int	i;
	int	j;

	i = -1;
	visited = (int **)malloc(sizeof(int *) * game->hei);
	if (!visited)
		return (0);
	while (++i < game->hei - 1)
	{
		visited[i] = (int *)malloc(sizeof(int) * (game->wid + 1));
		if (!visited[i])
		{
			free_visited(visited, i + 1);
			return (0);
		}
		j = -1;
		while (j < game->wid)
			visited[i][++j] = 0;
	}
	return (visited);
}

void	dfs(t_game *game, t_check *check, int y, int x)
{
	const int	dy[4] = {1, -1, 0, 0};
	const int	dx[4] = {0, 0, 1, -1};
	int			ny;
	int			nx;
	int			i;

	check->visited[y][x] = 1;
	if (game->str_line[y * game->wid + x] == 'C')
		check->collectible -= 1;
	if (game->str_line[y * game->wid + x] == 'E')
	{
		game->valid_path = 1;
		return ;
	}
	i = -1;
	while (++i < 4)
	{
		ny = y + dy[i];
		nx = x + dx[i];
		if (game->str_line[ny * game->wid + nx] != '1' \
			&& !check->visited[ny][nx])
			dfs(game, check, ny, nx);
	}
}

void	init_check(t_game *game, t_check *check)
{
	check->visited = visited_init(game);
	check->y = game->hei;
	check->x = game->wid;
	check->collectible = game->all_col;
	game->valid_path = 0;
}

void	check_path(t_game *game)
{
	t_check	check;

	init_check(game, &check);
	dfs(game, &check, game->player_y, game->player_x);
	if (!game->valid_path || check.collectible > 0)
		print_err("Map error Impossible design");
	free_visited(check.visited, game->hei);
}

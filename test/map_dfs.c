/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_dfs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjyu <seungjyu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 16:23:43 by seungjyu          #+#    #+#             */
/*   Updated: 2023/11/13 21:37:32 by seungjyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

void	free_visited(int **visited) // visited 배열 free
{
	int	i;

	i = 0;
	while (visited[i++])
	{
		free(visited[i]);
		visited[i] = 0;
	}
	free(visited);
	visited = 0;
}

int	**visited_init(t_game *game) // visited 배열 생성
{
	int	**visited;
	int	i;
	int	j;

	i = -1;
	visited = (int **)malloc(sizeof(int *) * game->hei);
	if (!visited)
		return(0);
	while (++i < game->hei)
	{
		visited[i] = (int *)malloc(sizeof(int) * (game->wid + 1));
		if (!visited[i])
		{
			free_visited(visited);
			return (0);
		}
		j = -1;
		while (j < game->wid)
			visited[i][++j] = 0; // visited 배열을 0으로 초기화
	}
	return (visited);
}

void	dfs(t_game *game, t_check *check, int y, int x)
{
	const int	dy[4] = {1, -1, 0, 0};
	const int	dx[4] = {0, 0, 1, -1}; // 네 방향 탐색
	int			ny;
	int			nx;
	int			i;

	check->visited[y][x] = 1;
	if (game->str_line[y * game->wid + x] == 'C')
		check->collectible -= 1;
	if (game->str_line[y * game->wid + x] == 'E')
	{
		game->valid_path = 1; // 출구가 존재하므로 유효한 경로로 임시 지정
		return ;
	}
	i = -1;
	while (++i < 4)
	{
		ny = y + dy[i];
		nx = x + dx[i];
		if (game->str_line[ny * game->wid + nx] != '1' && !check->visited[ny][nx]) // 새로운 좌표가 벽이 아니고 방문하지 않았을 떄 dfs 탐색
			dfs(game, check, ny, nx);
	}
}

void	init_check(t_game *game, t_check *check)
{
	check->visited = visited_init(game); // visited 배열 입력
	check->y = game->hei; // 세로길이 입력
	check->x = game->wid; // 가로길이 입력
	check->collectible = game->all_col; // 콜렉터블의 개수 입력
}

void	check_path(t_game *game)
{
	t_check	check;

	init_check(game, &check); // check 구조체 초기화
	dfs(game, &check, game->player_y, game->player_x); // dfs 깊이우선탐색 실행 (완탐 한번 걸기)
	if (!game->valid_path || check.collectible > 0) // 탈출구를 못찾았거나 존재하는 콜렉터블을 모두 지우지 못했을 시 경로가 존재 x
		print_err("Map error Impossible design");
	free_visited(check.visited); // visited 배열 free
}

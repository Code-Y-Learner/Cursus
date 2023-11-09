/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjyu <seungjyu@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:26:41 by youjeon           #+#    #+#             */
/*   Updated: 2023/11/08 18:07:22 by seungjyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

t_img	img_init(void *mlx)
{
	t_img	rt;
	int		wid;
	int		hei;

	rt.land = mlx_xpm_file_to_image(mlx, "./images/land.xpm", &wid, &hei);
	rt.wall = mlx_xpm_file_to_image(mlx, "./images/wall.xpm", &wid, &hei);
	rt.chara = mlx_xpm_file_to_image(mlx, "./images/chara.xpm", &wid, &hei);
	rt.generator = mlx_xpm_file_to_image(mlx, "./images/generator.xpm", &wid, &hei);
	rt.portal = mlx_xpm_file_to_image(mlx, "./images/portal_closed.xpm", &wid, &hei);
	rt.portal2 = mlx_xpm_file_to_image(mlx, "./images/portal_opened.xpm", &wid, &hei);
	return (rt);
}

void	put_img(t_game *g, int w, int h)
{
	if (g->str_line[h * g->wid + w] == '1')
	{
		mlx_put_image_to_window(g->mlx, g->win, g->img.wall, w * 64, h * 64);
	}
	else if (g->str_line[h * g->wid + w] == 'C')
	{
		mlx_put_image_to_window(g->mlx, g->win, g->img.generator, w * 64, h * 64);
	}
	else if (g->str_line[h * g->wid + w] == 'P')
	{
		mlx_put_image_to_window(g->mlx, g->win, g->img.chara, w * 64, h * 64);
	}
	else if (g->str_line[h * g->wid + w] == 'E' && g->all_col == g->col_cnt)
	{
		mlx_put_image_to_window(g->mlx, g->win, g->img.portal2, w * 64, h * 64);
	}
	else if (g->str_line[h * g->wid + w] == 'E')
	{
		mlx_put_image_to_window(g->mlx, g->win, g->img.portal, w * 64, h * 64);
	}
	else
	{
		mlx_put_image_to_window(g->mlx, g->win, g->img.land, w * 64, h * 64);
	}
}

void	setting_img(t_game *game)
{
	int		hei;
	int		wid;

	hei = 0;
	while (hei < game->hei)
	{
		wid = 0;
		while (wid < game->wid)
		{
			put_img(game, wid, hei);
			wid++;
		}
		hei++;
	}
}

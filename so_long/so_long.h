/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjyu <seungjyu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 18:15:01 by youjeon           #+#    #+#             */
/*   Updated: 2023/11/17 19:40:17 by seungjyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# include <stdlib.h>
# include "./mlx/mlx.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# define X_EVENT_KEY_PRESS			2
# define X_EVENT_KEY_RELEASE		3
# define X_EVENT_KEY_EXIT		17
# define KEY_ESC		53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2

typedef struct s_img {
	void	*chara;
	void	*generator;
	void	*land;
	void	*portal;
	void	*portal2;
	void	*wall;
}				t_img;

typedef struct s_check
{
	int	y;
	int	x;
	int	collectible;
	int	**visited;
}				t_check;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_img	img;
	int		wid;
	int		hei;
	int		player_x;
	int		player_y;
	char	*str_line;
	int		all_col;
	int		col_cnt;
	int		walk_cnt;
	int		valid_path;
}				t_game;

char	*check_line2(char *str);
char	*get_buf(int fd, char *str);
char	*ft_strjoin_expand(char *s1, char const *s2);
char	*check_line(char *str);
char	*get_next_line(int fd);
int		ft_strlen(const char *str);
void	ft_bzero(void *s, size_t n);
char	*ft_strchr(char *s, int c);
void	*ft_memmove(void *dest, const void *src, size_t n);
char	*ft_clear(char **s);
char	*ft_strjoin_expand(char *s1, char const *s2);
char	*ft_strdup_without_newline(char *s);
int		ft_strlcpy_without_newline(char *dst, char *src, int len);
char	*ft_strjoin_without_newline(char *s1, char *s2);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
t_img	img_init(void *mlx);
void	put_img(t_game *g, int w, int h);
void	setting_img(t_game *game);
void	map_read(char *filename, t_game *game);
void	map_check_wall(t_game *game);
void	map_check_params(t_game *game);
void	map_check_position(t_game *game);
void	map_check(t_game *game);
void	free_visited(int **visited, int hei);
int		**visited_init(t_game *game);
void	dfs(t_game *game, t_check *check, int y, int x);
void	init_check(t_game *game, t_check *check);
void	check_path(t_game *game);
int		clear_game(t_game *game);
void	move_w(t_game *g);
void	move_a(t_game *g);
void	move_s(t_game *g);
void	move_d(t_game *g);
void	print_err(char *message);
void	game_init(t_game *g, char *map);
int		exit_game(t_game *game);
int		press_key(int key_code, t_game *game);
int		main(int ac, char *av[]);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelahse <fbelahse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 12:00:04 by agimi             #+#    #+#             */
/*   Updated: 2023/08/30 13:24:54 by fbelahse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define WIDTH 2560
# define HEIGHT 1440
# define XFA 8
# define SP 3
# define NOR WIDTH
# define MSTEP 1
# define STEPS 0.03
# define DISTP 2.0
# define MSENS 180
# define RSTEP 0.087266
# define TOP 1
# define BOTTOM 2
# define LEFT 3
# define RIGHT 4
# define TOPBOTTOM 6
# define LEFTRIGHT 7
# define DOORV 8
# define DOORH 9
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 69
# endif

# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <MLX42/MLX42.h>

typedef struct smap
{
	char		*s;
	struct smap	*nxt;
	struct smap	*prv;
}	t_smap;

typedef struct map
{
	int		wi;
	int		he;
	char	**map;
}	t_map;

typedef struct color
{
	unsigned int	flo;
	unsigned int	cei;
}	t_col;

typedef struct mx
{
	mlx_t			*mlx;
	mlx_texture_t	*no;
	mlx_texture_t	*so;
	mlx_texture_t	*we;
	mlx_texture_t	*ea;
	mlx_texture_t	*door;
	mlx_texture_t	*tot[38];
	mlx_image_t		*img;
	int				*tno;
	int				*tso;
	int				*twe;
	int				*tea;
	int				*tdo;
}	t_mlx;

typedef struct paths
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
}	t_pts;

typedef struct cast
{
	double	sta;
	double	ani;
	int		side[2560];
	double	ang[2560];
	double	dx[2560];
	double	dy[2560];
	double	rx[2560];
	double	ry[2560];
	double	dis[2560];
	double	hs;
	int		i;
}	t_cas;

typedef struct dline
{
	double	dx;
	double	dy;
	double	ste;
	double	xi;
	double	yi;
	double	x;
	double	y;
	int		gx;
	int		gy;
}	t_line;

typedef struct text
{
	int		*tex;
	int		x;
	double	y;
	double	yinc;
	int		idx;
	double	coh;
	int		wid;
	int		hei;
}	t_text;

typedef struct cub3D
{
	struct map		*map;
	struct color	*col;
	struct mx		*mx;
	struct paths	*pts;
	struct smap		*sma;
	double			px;
	double			py;
	float			pdx;
	float			pdy;
	double			pan;
	float			fov;
	int				fd;
}	t_cub;

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~LIBFT~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void			ft_putstr_fd(char *s, int fd);
int				ft_strlen(const char *a);
void			ft_putchar_fd(char c, int fd);
char			*get_next_line(int fd);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strdup(const char *s1);
char			*ft_clean(char *c);
int				ft_atoi(const char *str);
int				ft_isspace(size_t c);
int				ft_sisspace(char *c);
void			ft_lstadd_back_m(t_smap **a, t_smap *new);
t_smap			*ft_lstlast_m(t_smap *lst);
t_smap			*ft_lstblast_m(t_smap *lst);
t_smap			*ft_lstnew_m(char *s);
void			clear_smap(t_smap **sma);
int				ft_lstsize(t_smap *sma);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_isplayer(size_t c);
int				is_ascii(char c);
char			*ft_itoa(int n);
char			*ft_strjoin(char *s1, char const *s2);
int				is_col(char *c);
char			*ft_strchr(const char *s, int c);

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~LIBFT~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void			init(t_cub *cub, char *av);
void			open_map(t_cub *cub, char *fd);
void			get_out_s(t_cub *cub, char *s);
void			read_map(t_cub *cub);
void			face_path(t_cub *cub, char *lin); 
void			color_set(t_cub *cub, char *lin);
unsigned int	get_rgba(int r, int g, int b, int a);
void			clean_map(t_cub *cub, t_smap *smap);
void			check_map(t_cub *cub, t_smap *sma);
void			loop(t_cub *cub);
void			flo_cei(void *par);
void			smap_map(t_cub *cub);
void			move(void *par);
void			cast(void *pra);
void			mouse(double x, double y, void *par);
void			init_texture(t_cub *cub);
void			side_select(t_cub *cub, t_cas *cas, int i);
void			texture_select(t_cub *cub, t_cas *cas, t_text *text);
void			door(void *par);
void			tot(void *par);
void			print_texture(t_cub *cub, t_cas *cas, t_text *text);
void			free_all(t_cub *cub);
bool			wall_check(char **map, t_cas *cas, double ol_x, double ol_y);
void			door_check(t_cub *cub, t_cas *cas, int i);

#endif

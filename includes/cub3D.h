/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 12:00:04 by agimi             #+#    #+#             */
/*   Updated: 2023/07/31 12:46:04 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define WIDTH 2560
# define HEIGHT 1440
# define XFA 16
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 69
# endif

# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include <stdio.h>
# include <stdlib.h>
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
	mlx_image_t		*img;
}	t_mlx;

typedef struct paths
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
}	t_pts;

typedef struct cub3D
{
	struct map		*map;
	struct color	*col;
	struct mx		*mx;
	struct paths	*pts;
	struct smap		*sma;
	int				fd;
}	t_cub;

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~LIBFT~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void			ft_putstr_fd(char *s, int fd);
size_t			ft_strlen(const char *a);
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

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~LIBFT~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void			init(t_cub *cub, char *av);
void			open_map(t_cub *cub, char *fd);
void			get_out_s(t_cub *cub, char *s);
void			read_map(t_cub *cub);
void			face_path(t_cub *cub, char *lin);
void			color_set(t_cub *cub, char *lin);
unsigned int	get_rgba(int r, int g, int b);
void			clean_map(t_cub *cub, t_smap *smap);
void			check_map(t_cub *cub, t_smap *sma);
void			loop(void *par);
void			smap_map(t_cub *cub);

#endif
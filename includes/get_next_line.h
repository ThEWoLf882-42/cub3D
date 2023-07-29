/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 13:03:54 by agimi             #+#    #+#             */
/*   Updated: 2023/07/29 10:28:57 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 69
# endif

char	*get_next_line(int fd);
size_t	ft_strleng(char *s);
char	*ft_strchrg(char *s, int c);
char	*ft_strjoing(char *naah, char *buff);
char	*thisone(char *naah);
char	*notthisone(char *naah);

#endif
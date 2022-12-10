/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 14:58:14 by cprojean          #+#    #+#             */
/*   Updated: 2022/12/08 18:18:30 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 15
# endif

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);

char	*ft_strnjoin(char *s1, char *s2, size_t index);

int		is_backslash(char *str);

size_t	ft_strlen(char *str);

void	ft_strcut(char *buf, size_t index);

int		how_many_backslash(char *buf);


#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 14:57:39 by cprojean          #+#    #+#             */
/*   Updated: 2022/12/07 19:03:20 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*array;
	int			index;
	int			isbackslash;

	array = malloc(sizeof(char));
	array[0] = 0;
	index = 0;
	if(ft_strlen(buf) != 0)
		
	while (read(fd, buf, BUFFER_SIZE))
	{
		// printf("\n buf :%s\n", buf);
		if (is_backslash(buf) > 0)
		{
			isbackslash = is_backslash(buf);
			return (ft_strnjoin(array, buf, isbackslash));
		}
		array = ft_strnjoin(array, buf, BUFFER_SIZE);
	}
	return (array);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 14:57:39 by cprojean          #+#    #+#             */
/*   Updated: 2022/12/06 15:22:17 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*buf[BUFFER_SIZE];

	read(fd, buf, BUFFER_SIZE);
	find_line(buf);
	return (*buf);
}

char	*find_line(char *buf)
{
	int	index;

	index = 0;
	while (buf[index] && index < BUFFER_SIZE)
	{
		if (buf[index] == '\n')
			return (index);
		index++;
	}
	buf[index] = '\0';
}

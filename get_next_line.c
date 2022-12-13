/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:34:30 by cprojean          #+#    #+#             */
/*   Updated: 2022/12/13 00:23:04 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

char	*get_next_line(int fd)
{
	static char buf[BUFFER_SIZE + 1];
	char		*array;
	ssize_t		reader;

	array = malloc(sizeof(char));
	if (buf[0] == 0)
		if (!(reader = read(fd, buf, BUFFER_SIZE)))
			return (NULL);
	while (where_backslash(buf) == -1 && reader != -1 && reader != 0)
	{
		array = ft_strnjoin(array, buf, BUFFER_SIZE);
		reader = read(fd, buf, BUFFER_SIZE);
		if (reader == -1)
			return (NULL);
	}
	if (where_backslash(buf) > 0)
	{
		array = ft_strnjoin(array, buf, where_backslash(buf));
		ft_buf_reset(buf, where_backslash(buf));
		return (array);
	}
	free(array);
	return (NULL);
}

void	ft_buf_reset(char *buf, int index)
{
	size_t	runner;
	size_t	flag;

	flag = index;
	runner = 0;
	while (buf[runner] && index <= BUFFER_SIZE)
	{
		if (runner > BUFFER_SIZE - flag)
			buf[runner] = '\0';
		else
			buf[runner] = buf[index];
		runner++;
		index++;
	}
}

ssize_t	where_backslash(char *buf)
{
	ssize_t	runner;

	runner = 0;
	while (buf[runner])
	{
		if (buf[runner] == '\n')
			return (runner + 1);
		runner++;
	}
	return (-1);
}

size_t	ft_strlen(char *str)
{
	size_t	index;

	if (!str)
		return (0);
	index = 0;
	while(str[index])
	{
		index++;
	}
	return (index);
}

char	*ft_strnjoin(char *s1, char *s2, size_t index)
{
	size_t		sizearray;
	size_t		sizestring;
	size_t		runner;
	size_t		size;
	char		*array;

	runner = 0;
	sizearray = ft_strlen(s1);
	sizestring = ft_strlen(s2);
	size = sizearray + index + 1;
	array = malloc(sizeof(char) * (size));
	if (!array)
		return (NULL);
	while (runner < sizearray)
	{
		array[runner] = s1[runner];
		runner++;
	}
	runner = 0;
	while (runner < sizestring && runner < index)
	{
		array[runner + sizearray] = s2[runner];
		runner++;
	}
	array[runner + sizearray] = '\0';
	free(s1);
	return (array);
}

int main()
{
	int fd;
	fd = open("42.txt", O_RDONLY);
	// int i = 0;
	// char *str;
	// while (i < 10)
	// {
	// 	str = get_next_line(fd);
	// 	printf("%s", get_next_line(fd));
	// 	free(str);
	// 	i++;
	// }
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
}

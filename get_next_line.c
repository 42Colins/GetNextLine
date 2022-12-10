/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 14:57:39 by cprojean          #+#    #+#             */
/*   Updated: 2022/12/10 18:25:51 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*array;
	int			index;
	int			reader;
	size_t		isbackslash;

	array = malloc(sizeof(char));
	array[0] = 0;
	index = 0;
	if(buf[0] != 0)
	{
		isbackslash = is_backslash(buf);
		array = buf;
		buf[0] = 0;
		ft_strcut(array, isbackslash);
		while (how_many_backslash(array) > 1)
			ft_strcut(array, is_backslash(array));
		return (array);
	}
	//reader = read(fd, buf, BUFFER_SIZE);
	if (reader == -1)
		return (NULL);
	while (read(fd, buf, BUFFER_SIZE) != 0)
	{
		if (how_many_backslash(buf) >= 1)
		{
			isbackslash = is_backslash(buf);
			return (ft_strnjoin(array, buf, isbackslash));
		}
		array = ft_strnjoin(array, buf, BUFFER_SIZE);
	}
	array[BUFFER_SIZE + 1] = '\0';
	return (array);
}

char	*ft_strnjoin(char *s1, char *s2, size_t index)
{
	int		sizearray;
	int		sizestring;
	int		runner;
	char	*array;

	runner = 0;
	sizearray = ft_strlen(s1);
	sizestring = ft_strlen(s2);
	array = malloc(sizeof(char) * (sizearray + sizestring - (sizestring - index - 1)) + 1);
	if (!array)
		return (NULL);
	while (runner < sizearray)
	{
		array[runner] = s1[runner];
		runner++;
	}
	runner = 0;
	while (runner < sizestring && runner <= index)
	{
		array[runner + sizearray] = s2[runner];
		runner++;
	}
	array[runner + sizearray] = '\0';
	return (array);
}

int	is_backslash(char *str)
{
	int	index;

	index = 0;
	while (str[index])
	{
		if (str[index] == '\n')
			return (index);
		index++;
	}
	return (0);
}

size_t	ft_strlen(char *str)
{
	size_t	index;

	index = 0;
	while(str[index])
	{
		index++;
	}
	return (index);
}

void	ft_strcut(char *buf, size_t index)
{
	size_t	runner;
	size_t	flag;

	flag = index;
	runner = 0;
	//index += 1;
	while(runner <= BUFFER_SIZE && runner < flag && buf[index])
	{
		buf[runner++] = buf[index++];
	}
	buf[runner] = '\0';
}

int	how_many_backslash(char *buf)
{
	int	count;
	int	index;

	index = 0;
	count = 0;
	while (buf[index])
	{
 		if (buf[index] == '\n')
			count++;
		index++;
	}
	return (count);
}

int main()
{
	int fd;
	fd = open("42.txt", O_RDONLY);
	//get_next_line(fd);
	int i = 0;
	// while (i < 10)
	// {
	// 	printf("%s", get_next_line(fd));
	// 	i++;
	// }
	// printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
}

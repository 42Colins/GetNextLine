/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 15:48:24 by cprojean          #+#    #+#             */
/*   Updated: 2022/12/07 21:27:26 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strnjoin(char *s1, char *s2, size_t index)
{
	int		sizearray;
	int		sizestring;
	int		runner;
	char	*array;

	runner = 0;
	sizearray = ft_strlen(s1);
	sizestring = ft_strlen(s2);
	array = malloc(sizeof(char) * (sizearray + (sizestring - index)) + 1);
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

char	*ft_strcut(char *buf, size_t index)
{
	size_t	runner;

	runner = 0;
	while(index <= BUFFER_SIZE)
	{
		buf[runner] = buf[index];
		runner++;
		index++;
	}
	return(buf);
}
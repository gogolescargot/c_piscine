/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 20:50:38 by ggalon            #+#    #+#             */
/*   Updated: 2023/08/30 20:15:03 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft.h"

int	**ft_free_array(int **map, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		free(map[i]);
	free(map);
	return (NULL);
}

int	**ft_create_map_array(char *str_file, int size, char *chars, int **map)
{
	int	i;
	int	row;
	int	column;

	i = ft_get_eol(str_file);
	row = 0;
	column = 0;
	while (++i < size * size + size + ft_get_eol(str_file))
	{
		if (str_file[i] == 10)
		{
			row++;
			map[row] = malloc(sizeof(int) * (size));
			if (!map[row])
				return (ft_free_array(map, size));
			column = 0;
			i++;
		}
		map[row][column] = ft_strstr_ind(chars, str_file[i]);
		column++;
	}
	return (map);
}

int	**ft_create_map(char *str_file, int size, char *chars)
{
	int	**map;
	int	row;
	int	column;

	row = 0;
	column = 0;
	map = malloc(sizeof(int *) * (size));
	if (!map)
		return (NULL);
	map[row] = malloc(sizeof(int) * (size));
	if (!map[row])
		return (ft_free_array(map, size));
	map = ft_create_map_array(str_file, size, chars, map);
	if (!map)
	{
		free(map);
		return (NULL);
	}
	return (map);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 17:06:17 by ggalon            #+#    #+#             */
/*   Updated: 2023/08/20 17:06:18 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	count_views(int array[6][6], int x, int y);

int	ft_dup_line(int array[6][6], int i)
{
	int	j;
	int	o;
	int	k;
	int	to_find;

	j = 0;
	o = 0;
	k = 0;
	while (j++ < 4)
	{
		to_find = array[i][j];
		while (k++ < 4)
		{
			if (array[i][k] == to_find && to_find != 0)
				o++;
		}
		k = 0;
		if (o > 1)
			return (1);
		o = 0;
	}
	return (0);
}

int	ft_dup_column(int array[6][6], int j)
{
	int	i;
	int	o;
	int	k;
	int	to_find;

	i = 0;
	o = 0;
	k = 0;
	while (i++ < 4)
	{
		to_find = array[i][j];
		while (k++ < 4)
		{
			if (array[k][j] == to_find && to_find != 0)
				o++;
		}
		k = 0;
		if (o > 1)
			return (1);
		o = 0;
	}
	return (0);
}

int	check_line(int array[6][6], int i)
{
	if (array[i][0] <= count_views(array, i, 0))
		return (1);
	if (array[i][5] <= count_views(array, i, 5))
		return (1);
	if (ft_dup_line(array, i) == 1)
		return (1);
	return (0);
}

int	check_column(int array[6][6], int j)
{
	int	temp;

	temp = -1;
	if (array[0][j] <= count_views(array, 0, j))
		return (1);
	if (array[5][j] <= count_views(array, 5, j))
		return (1);
	if (ft_dup_column(array, j) == 1)
		return (1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_views.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 15:00:51 by ggalon            #+#    #+#             */
/*   Updated: 2023/08/20 15:00:52 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	count_views_up(int array[6][6], int x, int y)
{
	int	max;
	int	max_it;

	max_it = 1;
	max = array[x + 1][y];
	while (x++ < 4)
	{
		if (array[x][y] > max)
		{
			max = array[x][y];
			max_it++;
		}
	}
	return (max_it);
}

int	count_views_down(int array[6][6], int x, int y)
{
	int	max;
	int	max_it;

	max_it = 1;
	max = array[x - 1][y];
	while (x-- >= 0)
	{
		if (array[x][y] > max)
		{
			max = array[x][y];
			max_it++;
		}
	}
	return (max_it);
}

int	count_views_left(int array[6][6], int x, int y)
{
	int	max;
	int	max_it;

	max_it = 1;
	max = array[x][y + 1];
	while (y++ < 4)
	{
		if (array[x][y] > max)
		{
			max = array[x][y];
			max_it++;
		}
	}
	return (max_it);
}

int	count_views_right(int array[6][6], int x, int y)
{
	int	max;
	int	max_it;

	max_it = 1;
	max = array[x][y - 1];
	while (y-- >= 0)
	{
		if (array[x][y] > max)
		{
			max = array[x][y];
			max_it++;
		}
	}
	return (max_it);
}

int	count_views(int array[6][6], int x, int y)
{
	if (x == 0 && y > 0 && y < 5)
		return (count_views_up(array, x, y));
	else if (x == 5 && y > 0 && y < 5)
		return (count_views_down(array, x, y));
	else if (y == 0 && x > 0 && x < 5)
		return (count_views_left(array, x, y));
	else if (y == 5 && x > 0 && x < 5)
		return (count_views_right(array, x, y));
	return (0);
}

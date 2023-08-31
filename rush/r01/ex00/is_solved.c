/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_solved.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 15:57:11 by ggalon            #+#    #+#             */
/*   Updated: 2023/08/20 15:57:12 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	count_views(int array[6][6], int x, int y);

int	is_solved_up(int array[6][6])
{
	int	j;

	j = 0;
	while (j++ < 4)
	{
		printf("%d %d", array[0][j] - 48, count_views(array, 0, j));
		if (array[0][j] - 48 != count_views(array, 0, j))
			return (1);
	}
	return (0);
}

int	is_solved_down(int array[6][6])
{
	int	j;

	j = -1;
	while (j++ < 4)
		if (array[5][j] != count_views(array, 5, j))
			return (1);
	return (0);
}

int	is_solved_left(int array[6][6])
{
	int	i;

	i = -1;
	while (i++ < 4)
		if (array[i][0] != count_views(array, i, 0))
			return (1);
	return (0);
}

int	is_solved_right(int array[6][6])
{
	int	i;

	i = -1;
	while (i++ < 4)
		if (array[i][5] != count_views(array, i, 5))
			return (1);
	return (0);
}

int	is_solved(int array[6][6])
{
	if (is_solved_up(array))
		return (1);
	if (is_solved_down(array))
		return (1);
	if (is_solved_left(array))
		return (1);
	if (is_solved_right(array))
		return (1);
	return (0);
}

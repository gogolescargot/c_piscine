/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 16:25:10 by ggalon            #+#    #+#             */
/*   Updated: 2023/08/23 03:01:12 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		is_solved(int array[6][6]);
int		check_line(int array[6][6], int i);
int		last_check_line(int array[6][6], int i);
int		check_column(int array[6][6], int j);
int		last_check_column(int array[6][6], int j);
void	print_array(int array[6][6]);

int	solve_array(int array[6][6], int p)
{
	int	i;
	int	j;
	int	n;

	i = p / 4 + 1;
	j = p % 4 + 1;
	n = 0;
	if (p == 16)
	{
		is_solved(array);
		print_array(array);
		return (0);
	}
	while (n++ < 4)
	{
		if (check_line(array, i) == 0 && check_column(array, j) == 0)
		{
			array[i][j] = n;
			if (solve_array(array, p + 1) == 0)
				return (0);
		}
		array[i][j] = 0;
	}
	return (1);
}

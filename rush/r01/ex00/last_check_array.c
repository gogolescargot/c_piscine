/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_check_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 22:49:22 by ggalon            #+#    #+#             */
/*   Updated: 2023/08/20 22:49:24 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	count_views(int array[6][6], int x, int y);
int	ft_dup_line(int array[6][6], int i);
int	ft_dup_column(int array[6][6], int j);

int	last_check_line(int array[6][6], int i)
{
	if (array[i][0] <= count_views(array, i, 0))
		return (1);
	if (array[i][5] <= count_views(array, i, 5))
		return (1);
	if (ft_dup_line(array, i) == 1)
		return (1);
	return (0);
}

int	last_check_column(int array[6][6], int j)
{
	if (array[0][j] == count_views(array, 0, j))
		return (1);
	if (array[5][j] == count_views(array, 5, j))
		return (1);
	if (ft_dup_column(array, j) == 1)
		return (1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_square_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 13:34:56 by gpachot           #+#    #+#             */
/*   Updated: 2023/08/30 18:23:46 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft.h"

int	ft_print_map(int **tab, char *chars, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size)
	{
		while (j < size)
		{
			ft_putchar(chars[tab[i][j]]);
			j++;
		}
		write(1, "\n", 1);
		j = 0;
		i++;
	}
	return (0);
}

int	ft_fill_square(int **tab, int i, int j, int max)
{
	int	i_init;
	int	j_init;

	i_init = i;
	j_init = j;
	while (i < i_init + max)
	{
		while (j < j_init + max)
		{
			tab[i][j] = 2;
			j++;
		}
		j = j_init;
		i++;
	}
	return (0);
}

int	ft_test_square(int **tab, int i, int j, int size)
{
	int	size_square;
	int	i_backup;
	int	j_backup;

	size_square = 0;
	while (i < size - size_square && j < size - size_square)
	{
		i_backup = i;
		while (i <= i_backup + size_square)
		{
			j_backup = j;
			while (j <= j_backup + size_square)
			{
				if (tab[i][j] != 0)
					return (size_square);
				j++;
			}
			j = j_backup;
			i++;
		}
		i = i_backup;
		size_square++;
	}
	return (size_square);
}

int	ft_max_square(int **tab, int *i_max, int *j_max, int size)
{
	int	i;
	int	j;
	int	size_max;
	int	size_test;

	size_max = 0;
	i = 0;
	j = 0;
	while (i < size)
	{
		while (j < size)
		{
			size_test = ft_test_square(tab, i, j, size);
			if (size_test > size_max)
			{
				*i_max = i;
				*j_max = j;
				size_max = size_test;
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (size_max);
}

int	ft_square_map(int **tab, int size, char *chars)
{
	int	i;
	int	j;
	int	max;

	i = 0;
	j = 0;
	max = ft_max_square(tab, &i, &j, size);
	ft_fill_square(tab, i, j, max);
	ft_print_map(tab, chars, size);
	return (0);
}
/*
int	main(void)
{
	int	tab[10][10];
	int	i;
	int	j;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			tab[i][j] = 0;
			j++;
		}
		i++;
	}
	tab[3][3] = 1;
	tab[7][3] = 1;
	tab[3][5] = 1;
	tab[0][9] = 1;
	tab[5][0] = 1;
	tab[3][9] = 1;
	tab[2][9] = 1;
	ft_square_map(tab, 10);
	return (0);
}
*/
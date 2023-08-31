/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 13:24:55 by ggalon            #+#    #+#             */
/*   Updated: 2023/08/20 13:24:57 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		check_args(int argc, char *argv[]);
void	print_array(int array[6][6]);
int		*init_array(char **argv, int array[6][6]);
int		count_views(int array[6][6], int x, int y);
int		is_solved(int array[6][6]);
int		solve_array(int array[6][6], int p);
void	ft_putchar(int c);

int	main(int argc, char *argv[])
{
	int	array[6][6];

	if (check_args(argc, argv) == 0)
	{
		ft_putchar('E');
		ft_putchar('r');
		ft_putchar('r');
		ft_putchar('o');
		ft_putchar('r');
		return (1);
	}
	init_array(argv, array);
	solve_array(array, 0);
}

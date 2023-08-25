/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 13:57:29 by ggalon            #+#    #+#             */
/*   Updated: 2023/08/19 22:11:55 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_queens(int board[10][10])
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (i++ < 9)
	{
		j = -1;
		while (j++ < 9)
			if (board[i][j] == 1)
				ft_putchar(j + 48);
	}
	ft_putchar(10);
}

int	check_queens(int board[10][10], int x, int y)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (i++ < 9)
		if (board[i][y] == 1)
			return (0);
	while (j++ < 9)
		if (board[x][j] == 1)
			return (0);
	i = -1;
	j = -1;
	while (x - i++ > 0 && y - j++ > 0)
		if (board[x - i][y - j] == 1)
			return (0);
	i = -1;
	j = -1;
	while (x - i++ > 0 && y + j++ < 9)
		if (board[x - i][y + j] == 1)
			return (0);
	return (1);
}

int	ft_solve_queens(int board[10][10], int i)
{
	int	j;

	j = -1;
	if (i > 9)
	{
		ft_print_queens(board);
		i = 0;
	}
	while (j++ < 9)
	{
		if (check_queens(board, i, j))
		{
			board[i][j] = 1;
			if (ft_solve_queens(board, i + 1) == 1)
				return (1);
			board[i][j] = 0;
		}
	}
	return (0);
}

int	ft_ten_queens_puzzle(void)
{
	int	board[10][10];
	int	i;
	int	j;

	i = -1;
	while (i++ < 9)
	{
		j = -1;
		while (j++ < 9)
			board[i][j] = 0;
	}
	ft_solve_queens(board, 0);
	return (724);
}
/*
int	main(void)
{
	ft_ten_queens_puzzle();
}
*/

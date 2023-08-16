/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoizel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 09:43:24 by aoizel            #+#    #+#             */
/*   Updated: 2023/08/12 14:40:32 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);
/*{
	write(1, &c, 1);
}*/

void	rush_putchar(int i, int j, int x, int y)
{
	if (i == 0 && j == 0)
		ft_putchar('/');
	else if (i == 0 && j == (y - 1))
		ft_putchar('\\');
	else if (i == (x - 1) && j == 0)
		ft_putchar('\\');
	else if (i == (x - 1) && j == (y - 1))
		ft_putchar('/');
	else if (i == 0 || i == (x - 1))
		ft_putchar('*');
	else if (j == 0 || j == (y - 1))
		ft_putchar('*');
	else
		ft_putchar(' ');
}

void	rush(int x, int y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (x <= 0 || y <= 0)
		return ;
	while (j < y)
	{
		while (i < x)
		{
			rush_putchar(i, j, x, y);
			i++;
		}
		ft_putchar('\n');
		i = 0;
		j++;
	}
}

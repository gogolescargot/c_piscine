/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoizel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 09:15:46 by aoizel            #+#    #+#             */
/*   Updated: 2023/08/12 14:41:02 by ggalon           ###   ########.fr       */
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
		ft_putchar('A');
	else if (i == 0 && j == (y - 1))
		ft_putchar('C');
	else if (i == (x - 1) && j == 0)
		ft_putchar('A');
	else if (i == (x - 1) && j == (y - 1))
		ft_putchar('C');
	else if (i == 0 || j == 0 || i == (x - 1) || j == (y - 1))
		ft_putchar('B');
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

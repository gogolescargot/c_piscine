/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 14:10:52 by ggalon            #+#    #+#             */
/*   Updated: 2023/08/20 14:10:53 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putchar(int c)
{
	write(1, &c, 1);
}

void	print_array(int array[6][6])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i++ < 4)
	{
		while (j++ < 4)
		{
			ft_putchar(array[i][j] + 48);
			ft_putchar(32);
		}
		j = 0;
		ft_putchar(10);
	}
}

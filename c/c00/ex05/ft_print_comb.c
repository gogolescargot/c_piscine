/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 14:20:47 by ggalon            #+#    #+#             */
/*   Updated: 2023/08/09 17:55:01 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_number(int c, int d, int u, int sep)
{
	ft_putchar(c + 48);
	ft_putchar(d + 48);
	ft_putchar(u + 48);
	if (sep == 1)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_incrementor(int c, int d, int u)
{
	while (c != 7 || d != 8 || u != 9)
	{
		if (u > d && d > c && u > c)
		{
			ft_print_number(c, d, u, 1);
		}
		if (d == 9 && u == 9)
		{
			d = 0;
			c += 1;
		}
		else if (u == 9)
		{
			u = 0;
			d += 1;
		}
		else
		{
			u += 1;
		}
	}
	ft_print_number (7, 8, 9, 0);
}

void	ft_print_comb(void)
{
	int		u;
	int		d;
	int		c;

	c = 0;
	d = 1;
	u = 2;
	ft_incrementor(c, d, u);
}

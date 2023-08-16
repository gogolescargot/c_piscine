/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 18:32:47 by ggalon            #+#    #+#             */
/*   Updated: 2023/08/10 00:37:51 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_number(int m, int c, int d, int u)
{
	if ((d == m && u > c) || (d > m))
	{
		ft_putchar(m + 48);
		ft_putchar(c + 48);
		ft_putchar(' ');
		ft_putchar(d + 48);
		ft_putchar(u + 48);
		if (m != 9 || c != 8 || d != 9 || u != 9)
		{
			ft_putchar(',');
			ft_putchar(' ');
		}
	}
}

void	ft_condition(int *u, int *d, int *c, int *m)
{
	if (*c == 9 && *d == 9 && *u == 9)
	{
		*u = 0;
		*d = 0;
		*c = 0;
		*m += 1;
	}
	else if (*d == 9 && *u == 9)
	{
		*u = 0;
		*d = 0;
		*c += 1;
	}
	else if (*u == 9)
	{
		*u = 0;
		*d += 1;
	}
	else
	{
		*u += 1;
	}
}

void	ft_incrementor(int m, int c, int d, int u)
{
	while (m != 9 || c != 8 || d != 9 || u != 9)
	{
		ft_print_number(m, c, d, u);
		ft_condition(&u, &d, &c, &m);
	}
}

void	ft_print_comb2(void)
{
	int		m;
	int		c;
	int		d;
	int		u;

	m = 0;
	c = 0;
	d = 0;
	u = 1;
	ft_incrementor(m, c, d, u);
	ft_print_number (9, 8, 9, 9);
}

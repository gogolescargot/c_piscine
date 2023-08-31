/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 14:36:58 by ggalon            #+#    #+#             */
/*   Updated: 2023/08/28 16:17:12 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	sum(int i, int j);
int	subtract(int i, int j);
int	multiplication(int i, int j);
int	division(int i, int j);
int	modulo(int i, int j);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putnbr(-2);
		ft_putnbr(147483648);
	}
	else if (nb < 0)
	{
		ft_putchar('-');
		ft_putnbr(-nb);
	}
	else if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putchar (nb % 10 + 48);
	}
	else
	{
		ft_putchar(nb + 48);
	}
}

int	ft_atoi(char *str)
{
	int	i;
	int	j;
	int	m;
	int	r;

	i = 0;
	j = 0;
	m = 1;
	r = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			m *= -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		r += str[i] - 48;
		if (str[i + 1] >= 48 && str[i + 1] <= 57)
			r *= 10;
		i++;
	}
	return (r * m);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	(*p[5])(int x, int y);

	p[0] = sum;
	p[1] = subtract;
	p[2] = multiplication;
	p[3] = division;
	p[4] = modulo;
	if (argc != 4)
		return (-1);
	if (ft_strcmp(argv[2], "+") == 0)
		return (p[0](ft_atoi(argv[1]), ft_atoi(argv[3])), 0);
	else if (ft_strcmp(argv[2], "-") == 0)
		return (p[1](ft_atoi(argv[1]), ft_atoi(argv[3])), 0);
	else if (ft_strcmp(argv[2], "*") == 0)
		return (p[2](ft_atoi(argv[1]), ft_atoi(argv[3])), 0);
	else if (ft_strcmp(argv[2], "/") == 0)
		return (p[3](ft_atoi(argv[1]), ft_atoi(argv[3])), 0);
	else if (ft_strcmp(argv[2], "%") == 0)
		return (p[4](ft_atoi(argv[1]), ft_atoi(argv[3])), 0);
	else
		return (write(1, "0\n", 2), -1);
}

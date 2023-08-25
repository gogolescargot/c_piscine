/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 14:38:59 by ggalon            #+#    #+#             */
/*   Updated: 2023/08/21 14:39:01 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_putargv(int argc, char *argv[])
{
	int	i;

	i = 0;
	while (i++ < argc - 1)
	{
		ft_putstr(argv[i]);
		ft_putchar(10);
	}
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

int	main(int argc, char *argv[])
{
	int		i;
	int		j;
	int		indmin;
	char	*temp;

	i = 1;
	j = 1; 
	while (i < argc)
	{
		indmin = i;
		while (j < argc)
		{
			if (ft_strcmp(argv[j], argv[indmin]) < 0)
			{
				temp = argv[indmin];
				argv[indmin] = argv[j];
				argv[j] = temp;
				j = indmin;
			}
			j++;
		}
		i++;
		j = i;
	}
	ft_putargv(argc, argv);
}

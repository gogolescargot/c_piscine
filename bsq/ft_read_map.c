/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 21:35:40 by ggalon            #+#    #+#             */
/*   Updated: 2023/08/30 20:29:06 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft.h"

int	ft_get_eol(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 10)
		i++;
	return (i);
}

int	ft_get_size(char *str)
{
	int		i;
	int		j;
	int		int_size;
	char	*str_size;

	i = 0;
	j = 0;
	while (str[i] != 10)
		i++;
	str_size = malloc(sizeof(char) * (i - 3) + 1);
	if (!str_size)
	{
		free(str_size);
		return (-1);
	}
	while (j < i - 3)
	{
		str_size[j] = str[j];
		j++;
	}
	str_size[j] = 0;
	int_size = ft_atoi(str_size);
	free(str_size);
	return (int_size);
}

char	*ft_get_char(char *str)
{
	int		i;
	char	*tab;

	i = 0;
	tab = malloc(sizeof(char) * 3 + 1);
	if (!tab)
		return (0);
	while (str[i] != 0 && str[i] != 10)
		i++;
	if (str[i] == 0)
	{
		free(tab);
		return (0);
	}
	if (str[i - 1] > 31 && str[i - 1] < 127)
		tab[2] = str[i - 1];
	if (str[i - 2] > 31 && str[i - 2] < 127)
		tab[1] = str[i - 2];
	if (str[i - 3] > 31 && str[i - 3] < 127)
		tab[0] = str[i - 3];
	tab[3] = 0;
	return (tab);
}

int	ft_count_row(char *str)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	i = ft_get_eol(str) + 1;
	while (str[i])
	{
		if (str[i] == 10)
			n++;
		i++;
	}
	return (n);
}

int	ft_count_column(char *str)
{
	int	i;
	int	n;
	int	m;

	n = 0;
	m = 0;
	i = ft_get_eol(str) + 1;
	while (str[i] != 10 && str[i])
	{
		n++;
		i++;
	}
	i++;
	while (str[i] != 10 && str[i++])
	{
		m++;
		if (str[i] == 10 && m != n)
			return (-1);
		else if (str[i] == 10 && m == n)
		{
			i++;
			m = 0;
		}
	}
	return (n);
}

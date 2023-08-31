/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 15:57:01 by ggalon            #+#    #+#             */
/*   Updated: 2023/08/30 12:42:26 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strstr_occ(char *str, char to_find)
{
	int	i;
	int	o;

	i = 0;
	o = 0;
	while (str[i])
	{
		if (str[i] == to_find || to_find == 10)
			o++;
		i++;
	}
	return (o);
}

int	ft_strstr_ind(char *str, char to_find)
{
	int	i;
	int	o;

	i = 0;
	o = 0;
	while (str[i])
	{
		if (str[i] == to_find)
			return (i);
		i++;
	}
	return (-1);
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

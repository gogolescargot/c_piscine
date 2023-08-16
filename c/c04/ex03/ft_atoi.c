/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 18:46:58 by ggalon            #+#    #+#             */
/*   Updated: 2023/08/16 02:59:48 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
/*
#include <stdio.h>
#include <stdlib.h>
int main (int argc, char *argv[])
{
    printf("%d\n", ft_atoi(argv[1]));
	printf("%d\n", atoi(argv[1]));
}
*/

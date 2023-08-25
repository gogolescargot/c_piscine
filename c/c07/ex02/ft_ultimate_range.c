/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 11:22:56 by ggalon            #+#    #+#             */
/*   Updated: 2023/08/23 03:13:46 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	unsigned long	i;

	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	i = max - min;
	if (i > 2147483647)
		return (-1);
	*range = malloc(sizeof(int) * (max - min));
	if (!*range)
		return (-1);
	i = 0;
	while (min < max)
	{
		(*range)[i] = min;
		i++;
		min++;
	}
	return (i);
}
/*
#include <stdio.h>

int	main(int argc, char **argv)
{
	int *range;

	printf("%d",ft_ultimate_range(&range, atoi(argv[1]), atoi(argv[2])));
}
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 15:54:18 by ggalon            #+#    #+#             */
/*   Updated: 2023/08/19 21:31:17 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	unsigned int	temp;
	int				i;

	if (nb < 0)
		return (0);
	temp = 1;
	i = 1;
	while (i <= nb)
		temp *= i++;
	return (temp);
}
/*
#include <stdio.h>
#include <stdlib.h>
int	main(int argc, char *argv[])
{
	printf("%d",ft_iterative_factorial(atoi(argv[1])));
}
*/

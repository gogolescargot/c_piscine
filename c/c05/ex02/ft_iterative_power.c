/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 18:20:20 by ggalon            #+#    #+#             */
/*   Updated: 2023/08/19 20:40:48 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	temp;

	temp = nb;
	if (power < 0)
		return (0);
	if (power == 0 || (nb == 0 && power == 0))
		return (1);
	else 
	{
		while (power-- > 1)
			nb *= temp;
		return (nb);
	}
}
/*
#include <stdio.h>
#include <stdlib.h>
int main(int arc, char *argv[])
{
	printf("%d",ft_iterative_power(atoi(argv[1]), atoi(argv[2])));
}
*/

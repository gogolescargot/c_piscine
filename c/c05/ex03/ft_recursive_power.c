/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 18:43:45 by ggalon            #+#    #+#             */
/*   Updated: 2023/08/19 20:44:10 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0 || (nb == 0 && power == 0))
		return (1);
	if (power > 1)
		return (nb * ft_recursive_power(nb, power - 1));
	return (nb);
}
/*
#include <stdlib.h>
#include <stdio.h>
int main(int argc, char *argv[])
{
	printf("%d",ft_recursive_power(atoi(argv[1]), atoi(argv[2])));
}
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 01:53:20 by ggalon            #+#    #+#             */
/*   Updated: 2023/08/19 21:16:31 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	i = 2;
	if (nb <= 1)
		return (0);
	else if (nb == 2147483647)
		return (1);
	while (i < nb)
		if (nb % i++ == 0)
			return (0);
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (nb == 2147483647)
		return (2147483647);
	else if (nb < 0)
		return (2);
	while (ft_is_prime(nb) == 0)
		nb++;
	return (nb);
}
/*
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
	printf("%d",ft_find_next_prime(atoi(argv[1])));
}
*/

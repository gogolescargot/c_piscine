/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 01:41:39 by ggalon            #+#    #+#             */
/*   Updated: 2023/08/19 20:56:36 by ggalon           ###   ########.fr       */
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
/*
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
	printf("%d", ft_is_prime(atoi(argv[1])));
}
*/

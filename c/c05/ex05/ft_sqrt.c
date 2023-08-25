/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 19:38:46 by ggalon            #+#    #+#             */
/*   Updated: 2023/08/19 21:28:16 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	unsigned long	mid;
	unsigned long	start;
	unsigned long	end;

	start = 0;
	end = nb;
	if (nb < 0)
		return (0);
	while (start <= end)
	{
		mid = (start + end) / 2;
		if (mid * mid == (unsigned long)nb)
			return (mid);
		else if (mid * mid < (unsigned long)nb)
			start = mid + 1;
		else
			end = mid - 1;
	}
	return (0);
}
/*
#include <stdlib.h>
#include <stdio.h>
int	main(int argc, char *argv[])
{
	printf("%d",ft_sqrt(atoi(argv[1])));
}
*/

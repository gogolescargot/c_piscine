/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_transformation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matboyer <matboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 16:26:08 by matboyer          #+#    #+#             */
/*   Updated: 2023/08/27 16:36:09 by matboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	weight_counter(int nb)
{
	int	i;

	i = 0;
	while (nb >= 10)
	{
		i++;
		nb /= 10;
	}
	return (i);
}

int	calculate_power(int nb, int pow)
{
	int	i;
	int	result;

	i = 0;
	result = 1;
	if (pow <= 0)
		return (0);
	while (i < pow)
	{
		result = result * nb;
		i++;
	}
	return (result);
}

int	find_most_significient_digit(int nb, int log_nb)
{
	int	i;

	i = 0;
	if (log_nb == 1)
	{
		log_nb *= 10;
	}
	if (log_nb > 1)
	{
		while (nb >= log_nb)
		{
			nb -= log_nb;
			i++;
		}
	}
	else
	{
		return (nb);
	}
	return (i);
}

int	ft_stinky_malloc(int nb)
{
	int	temp;

	temp = nb;
	temp += 1;
	while (nb > 0)
	{
		temp += nb - 1;
		nb--;
	}
	return (temp);
}

int	*ft_int_decomp(int nb)
{
	int	left_most_digit ;
	int	weight ;
	int	*array;
	int	i;

	array = malloc(sizeof(int) * (weight_counter(nb)
				+ ft_stinky_malloc(weight_counter(nb))));
	i = 0;
	while (nb > 0)
	{
		left_most_digit = find_most_significient_digit(nb, 
				calculate_power(10, weight_counter(nb)));
		weight = calculate_power(10, weight_counter(nb));
		array[i] = left_most_digit;
		array[i + 1] = weight;
		if (weight == 0)
			weight = 1;
		nb -= weight * left_most_digit;
		i += 2;
	}
	i = 0;
	return (array);
}

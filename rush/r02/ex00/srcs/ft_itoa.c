/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmedjou <bmedjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 16:30:32 by bmedjou           #+#    #+#             */
/*   Updated: 2023/08/27 18:05:09 by bmedjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	weight_counter(int nb);

void	ft_swap(char *x, char *y)
{
	char	t;

	t = *x;
	*x = *y;
	*y = t;
}

char	*ft_reverse(char *buffer, int i, int j)
{
	while (i < j)
	{
		ft_swap(&buffer[i++], &buffer[j--]);
	}
	return (buffer);
}

char	*ft_itoa(int nb)
{
	int		i;
	int		j;
	int		r;
	char	*array;

	i = 0;
	j = -1;
	array = malloc(sizeof(char) * 10);
	while (j++ < weight_counter(nb))
	{
		while (nb > 0)
		{
			r = nb % 10;
			if (r >= 10)
				array[i++] = 'A' + (r - 10);
			else
				array[i++] = '0' + r;
			nb /= 10;
		}
		if (i == 0)
			array[i++] = '0';
	}
	array[i] = '\0';
	return (ft_reverse(array, 0, i - 1));
}

char	**fill_array(int *array, int size)
{
	char	**char_array;
	int		i;

	i = 0;
	char_array = malloc(sizeof(char) * 1000);
	while (i < size)
	{
		char_array[i] = ft_itoa(array[i]);
		i++;
	}
	char_array[i] = 0;
	return (char_array);
}

int	ft_atoi(char *str)
{
	int	i;
	int	m;
	int	r;

	i = 0;
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

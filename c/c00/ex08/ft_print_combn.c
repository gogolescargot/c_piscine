/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 02:11:38 by ggalon            #+#    #+#             */
/*   Updated: 2023/08/18 14:46:34 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_put_array(int array[], int n, int end)
{
	int	j;

	j = 0;
	while (j < n)
	{
		ft_putchar(array[j] + 48);
		j++;
	}
	if (end == 0)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
	j = 0;
}

int	ft_check_array(int array[], int array_max[], int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (array[i] != array_max[i])
			return (1);
		i++;
	}
	return (0);
}

void	ft_array_increment(int array[10], int array_max[], int n)
{
	int	i;

	i = 1;
	while (ft_check_array(array, array_max, n))
	{
		if (array[n - i] != array_max[n - i])
		{
			array[n - i] += 1;
		}
		else
		{
			while (array[n - i - 1] == array_max[n - i - 1])
				i++;
			array[n - i - 1] += 1;
			while (i >= 1)
			{
				array[n - i] = array[n - i - 1] + 1;
				i--;
			}
		}
		if (ft_check_array(array, array_max, n))
			ft_put_array(array, n, 0);
		else
			ft_put_array(array, n, 1);
	}
}

void	ft_print_combn(int n)
{
	int	array[10];
	int	array_max[10];
	int	i;
	int	j;

	if (n < 1 || n > 9)
		return ;
	i = -1;
	while (i++ < n - 1)
		array[i] = i;
	array[i] = 0;
	array_max[i] = 0;
	j = 0;
	while (i-- > 0)
		array_max[i] = 9 - j++;
	ft_put_array(array, n, 0);
	while (ft_check_array(array, array_max, n))
	{
		ft_array_increment(array, array_max, n);
	}
}

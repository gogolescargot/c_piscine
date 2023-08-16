/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 15:25:27 by ggalon            #+#    #+#             */
/*   Updated: 2023/08/10 17:33:36 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int		temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int		i;
	int		j;
	int		indmin;
	int		min;

	i = 0;
	j = 0; 
	while (i < size)
	{
		indmin = i;
		min = tab[i];
		while (j < size)
		{
			if (tab[j] < min)
			{
				min = tab[j];
				indmin = j;
			}
			j++;
		}
		ft_swap(&tab[i], &tab[indmin]);
		i++;
		j = i;
	}
}

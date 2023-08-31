/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 14:13:33 by ggalon            #+#    #+#             */
/*   Updated: 2023/08/28 18:23:45 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	trigger;

	i = -1;
	trigger = 0;
	while (++i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) < 0)
			trigger = 1;
		else if (f(tab[i], tab[i + 1]) > 0)
			trigger = -1;
		if (trigger != 0)
			break ;
	}
	while (++i < length - 1)
	{
		if (trigger == 1)
			if (f(tab[i], tab[i + 1]) > 0)
				return (0);
		if (trigger == -1)
			if (f(tab[i], tab[i + 1]) < 0)
				return (0);
	}
	return (1);
}
/*
int sort (int i, int j)
{
	return (i - j);
}

int main (void)
{
	int tab[] = {-2};
	printf("%d",ft_is_sort(tab, 1, sort));
}
*/

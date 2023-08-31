/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 16:33:56 by ggalon            #+#    #+#             */
/*   Updated: 2023/08/29 13:14:02 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_advanced_sort_string_tab(char **tab, int (*cmp) (char *, char *))
{
	int		i;
	int		size;
	char	*temp;

	i = 0;
	size = 0;
	while (tab[i])
	{
		size++;
		i++;
	}
	i = 0;
	while (i < size - 1)
	{
		if (cmp(tab[i], tab[i + 1]) > 0)
		{
			temp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = temp;
			i = -1;
		}
		i++;
	}
}
/*
int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (0);
}

int main (void)
{
	char *tab[] = {"test2", "test3"};
	ft_advanced_sort_string_tab(tab, ft_strcmp);
}
*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 16:25:06 by ggalon            #+#    #+#             */
/*   Updated: 2023/08/28 16:33:28 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	ft_sort_string_tab(char **tab)
{
	int		i;
	int		j;
	int		indmin;
	char	*temp;

	i = 0;
	j = 0; 
	while (tab[i])
	{
		indmin = i;
		while (tab[j])
		{
			if (ft_strcmp(tab[j], tab[indmin]) < 0)
			{
				temp = tab[indmin];
				tab[indmin] = tab[j];
				tab[j] = temp;
				j = indmin;
			}
			j++;
		}
		i++;
		j = i;
	}
}

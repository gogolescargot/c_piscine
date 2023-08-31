/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 18:19:25 by ggalon            #+#    #+#             */
/*   Updated: 2023/08/27 18:19:26 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char *str);

char	*ft_find_numbers(int size, char **keys, char**values, char *to_find)
{
	int	j;
	int	k;

	j = 0;
	k = 0;
	while (k < size)
	{
		while (keys[k][j] == to_find[j])
		{
			if (ft_strlen(keys[k]) != ft_strlen(to_find))
				break ;
			j++;
			if (j == ft_strlen(to_find))
				return (values[k]);
		}
		k++;
		j = 0;
	}
	return (0);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

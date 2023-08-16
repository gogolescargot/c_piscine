/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 23:50:17 by ggalon            #+#    #+#             */
/*   Updated: 2023/08/15 20:03:44 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (ft_strlen(to_find) == 0)
		return (str);
	else if (ft_strlen(to_find) == 0 && ft_strlen(str) == 0)
		return ("");
	while (str[i])
	{
		while (str[i + j] == to_find[j])
		{
			j++;
			if (j == ft_strlen(to_find))
				return (&str[i]);
		}
		i++;
		j = 0;
	}
	return (0);
}

/*
#include <string.h>
#include <stdio.h>
int main (int argc, char *argv[])
{
	printf("%s\n", strstr(argv[1], argv[2]));
	printf("%s\n", ft_strstr(argv[1], argv[2]));
}
*/

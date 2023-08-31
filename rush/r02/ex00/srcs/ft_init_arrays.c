/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_arrays.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 15:52:09 by ggalon            #+#    #+#             */
/*   Updated: 2023/08/27 16:55:39 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int		ft_strlen(char *str);
char	*ft_strndup(char *src, int n);

int	ft_count_nline(char *str)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (str[i])
	{
		if (str[i] == 10)
			n++;
		while (str[i] == 10)
			i++;
		i++;
	}
	return (n);
}

char	**ft_init_keys(char *str)
{
	char	**keys;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = -1;
	k = 0;
	keys = malloc(sizeof(char *) * (ft_count_nline(str)));
	if (!keys)
		return (NULL);
	while (++j < ft_count_nline(str))
	{
		while (str[i + k] != ':')
			k++;
		keys[j] = ft_strndup(&str[i], k);
		k = 0;
		while (str[i] != '\n')
			i++;
		while (str[i] == '\n')
			i++;
	}
	return (keys);
}

char	**ft_init_values(char *str)
{
	char	**values;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = -1;
	k = 0;
	values = malloc(sizeof(char *) * (ft_count_nline(str)));
	if (!values)
		return (NULL);
	while (++j < ft_count_nline(str))
	{
		while (str[i] != ':')
			i++;
		i++;
		while (str[i + k] != '\n')
			k++;
		values[j] = ft_strndup(&str[i], k);
		i += k + 1;
		k = 0;
		while (str[i] == '\n')
			i++;
	}
	return (values);
}

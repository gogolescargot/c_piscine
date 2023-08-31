/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trim2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:24:47 by ggalon            #+#    #+#             */
/*   Updated: 2023/08/27 16:55:58 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_char_printable(char c);
int		ft_strlen(char *str);
char	*ft_strndup(char *src, int n);
int		ft_count_words(char *str);

char	**ft_split(char *str)
{
	int		i;
	int		j;
	int		k;
	char	**split_str;

	i = 0;
	j = 0;
	k = 0;
	split_str = (char **)malloc(sizeof(char *)
			* (ft_count_words(str) + 1));
	if (!split_str)
		return (NULL);
	while (str[i])
	{
		while (str[i + j] && ft_char_printable(str[i + j]))
			j++;
		if (j != 0)
		{
			split_str[k] = (char *)malloc(sizeof(char) * j + 1);
			split_str[k++] = ft_strndup(&str[i], j);
		}
		i += j + 1;
		j = 0;
	}
	return (split_str[k] = 0, split_str);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strcat(char *dest, char *src)
{
	int	e;
	int	i;

	e = ft_strlen(dest);
	i = 0;
	while (src[i])
	{
		dest[e + i] = src[i];
		i++;
	}
	dest[e + i] = '\0';
	return (dest);
}

int	ft_ultimate_strlen(char **str, int size)
{
	int	i;
	int	total;

	total = 0;
	i = -1;
	while (i++ < size - 1)
	{
		total += ft_strlen(str[i]);
	}
	return (total);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*temp;
	int		i;

	if (size == 0)
	{
		temp = malloc(1);
		if (!temp)
			return (NULL);
		temp[0] = 0;
		return (temp);
	}
	temp = (char *)malloc(((size - 1) * (ft_strlen(sep))
				+ ft_ultimate_strlen(strs, size) + 1));
	ft_strcpy(temp, strs[0]);
	i = 1;
	while (i < size)
	{
		ft_strcat(temp, sep);
		ft_strcat(temp, strs[i]);
		i++;
	}
	return (temp);
}

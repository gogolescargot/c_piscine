/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 15:14:56 by ggalon            #+#    #+#             */
/*   Updated: 2023/08/23 03:08:33 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strndup(char *src, int n)
{
	char	*dest;
	int		i;

	i = 0;
	dest = (char *)malloc(n + 1);
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_strstr(char *str, char to_find)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == to_find)
			return (1);
		i++;
	}
	return (0);
}

int	ft_count_words(char *str, char *charset)
{
	int	words;
	int	i;

	i = 0;
	words = 0;
	while (str[i])
	{
		while (str[i] && ft_strstr(charset, str[i]))
			i++;
		if (str[i] == '\0')
			return (words);
		while (str[i] && !ft_strstr(charset, str[i]))
			i++;
		words++;
	}
	return (words);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		j;
	int		k;
	char	**split_str;

	i = 0;
	j = 0;
	k = 0;
	split_str = (char **)malloc(sizeof(char *)
			* (ft_count_words(str, charset) + 1));
	while (str[i])
	{
		while (str[i + j] && !ft_strstr(charset, str[i + j]))
			j++;
		if (j != 0)
		{
			split_str[k] = (char *)malloc(sizeof(char) * j + 1);
			split_str[k] = ft_strndup(&str[i], j);
			k++;
		}
		i += j + 1;
		j = 0;
	}
	split_str[k] = 0;
	return (split_str);
}
/*
int	main(int argc, char **argv)
{
	ft_split(argv[1], argv[2]);
}
*/

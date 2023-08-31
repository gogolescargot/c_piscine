/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trim1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 15:31:19 by ggalon            #+#    #+#             */
/*   Updated: 2023/08/27 16:55:53 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_count_words(char *str);
char	**ft_split(char *str);
char	*ft_strjoin(int size, char **strs, char *sep);

int	ft_char_printable(char c)
{
	if (c < 33 || c > 126)
		return (0);
	return (1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strndup(char *src, int n)
{
	char	*dest;
	int		i;

	i = 0;
	dest = (char *)malloc(n + 1);
	if (!dest)
		return (NULL);
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_count_words(char *str)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (str[i])
	{
		while (str[i] && !ft_char_printable(str[i]))
			i++;
		if (!str[i])
			return (word);
		while (str[i] && ft_char_printable(str[i]))
			i++;
		word++;
	}
	return (word);
}

char	*ft_trim(char *str)
{
	return (ft_strjoin(ft_count_words(str), ft_split(str), " "));
}

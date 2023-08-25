/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 16:06:23 by ggalon            #+#    #+#             */
/*   Updated: 2023/08/24 21:39:09 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
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
/*
#include <stdio.h>

int main(void)
{
	char *A[] = {"compile", "la"};
	//printf("%d",ft_ultimate_strlen(A, 4));
	printf("%s",ft_strjoin(2, A, "<3"));
}
*/

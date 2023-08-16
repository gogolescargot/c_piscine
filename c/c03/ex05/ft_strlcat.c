/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 00:29:59 by ggalon            #+#    #+#             */
/*   Updated: 2023/08/15 21:24:40 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	e;
	unsigned int	i;

	e = ft_strlen(dest);
	i = 0;
	if (ft_strlen(dest) >= size)
		return (size + ft_strlen(src));
	while (i < size - e - 1 && src[i])
	{
		dest[e + i] = src[i];
		i++;
	}
	dest[e + i] = '\0';
	return (e + ft_strlen(src));
}

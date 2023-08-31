/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 19:20:18 by ggalon            #+#    #+#             */
/*   Updated: 2023/08/30 19:28:55 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft.h"

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int				e;
	unsigned int	i;

	e = ft_strlen(dest);
	i = 0;
	while (i < nb && src[i])
	{
		dest[e + i] = src[i];
		i++;
	}
	dest[e + i] = '\0';
	return (dest);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int		i;

	i = 0;
	while (i < n && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

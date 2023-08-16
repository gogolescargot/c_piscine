/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 23:30:22 by ggalon            #+#    #+#             */
/*   Updated: 2023/08/15 18:22:24 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

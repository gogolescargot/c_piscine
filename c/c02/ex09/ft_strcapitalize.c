/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 12:10:56 by ggalon            #+#    #+#             */
/*   Updated: 2023/08/14 12:15:05 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_alpha(char str)
{
	if ((str < 65 || str > 90) && (str < 97 || str > 122))
	{
		return (0);
	}
	return (1);
}

int	ft_str_is_numeric(char str)
{
	if ((str < 48 || str > 57))
	{
		return (0);
	}
	return (1);
}

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 65 && str[i] <= 90)
		{
			str[i] += 32;
		}
		i++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = ft_strlowcase(str);
	while (str[i])
	{
		if (ft_str_is_alpha(str[i]) || ft_str_is_numeric(str[i]))
		{
			while (ft_str_is_alpha(str[j]) || ft_str_is_numeric(str[j]))
			{
				j++;
			}
			if (str[i] >= 97 && str[i] <= 122)
				str[i] -= 32;
			i = j;
		}
		i++;
		j = i;
	}
	return (str);
}

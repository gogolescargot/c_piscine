/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 00:49:23 by ggalon            #+#    #+#             */
/*   Updated: 2023/08/27 16:55:34 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strndup(char *src, int n);

char	*ft_check_zero(char *str)
{
	int		i;
	int		j;
	char	*result;

	i = 0;
	j = 0;
	result = 0;
	while (str[i] == '0')
	{
		if (str[i + 1] == 0)
			return ("0");
		i++;
	}
	while (str[i + j])
	{
		j++;
	}
	result = ft_strndup(&str[i], j);
	return (result);
}

char	*ft_atoa(char *str)
{
	int		i;
	int		j;
	char	*result;

	i = 0;
	j = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == 43 || str[i] == 45)
		i++;
	while (str[i + j] >= 48 && str[i + j] <= 57)
		j++;
	result = ft_strndup(&str[i], j);
	return (ft_check_zero(result));
}

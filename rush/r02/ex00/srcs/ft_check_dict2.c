/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dict2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 15:21:21 by ggalon            #+#    #+#             */
/*   Updated: 2023/08/27 16:55:30 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str);

int	ft_strstr(int size, char **str, char *to_find)
{
	int	j;
	int	k;
	int	n;

	j = 0;
	k = 0;
	n = 0;
	while (k < size)
	{
		while (str[k][j] == to_find[j])
		{
			if (ft_strlen(str[k]) != ft_strlen(to_find))
				break ;
			j++;
			if (j == ft_strlen(to_find))
			{
				n++;
				break ;
			}
		}
		k++;
		j = 0;
	}
	return (n);
}

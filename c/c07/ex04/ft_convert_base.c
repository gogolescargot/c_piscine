/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 16:35:39 by ggalon            #+#    #+#             */
/*   Updated: 2023/08/23 00:10:37 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_strstr(char *str, char to_find);
int	ft_strlen(char *str, char *base, int mode);
int	ft_atoi_base(char *str, char *base);

void	ft_swap(char *a, char *b)
{
	int		temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

char	*ft_rev_int_tab(char *str, int size, int negative)
{
	int		i;
	int		j;

	i = negative;
	j = 0;
	while (j < size / 2)
	{
		ft_swap(&str[i], &str[size - j - 1]);
		i++;
		j++;
	}
	return (str);
}

char	*ft_int_to_base(int nbr, char *base)
{
	int		i;
	char	*str;
	int		negative;
	long	long_nbr;

	i = 0;
	negative = 0;
	str = malloc(40);
	long_nbr = (long)nbr;
	while (long_nbr != 0)
	{
		if (long_nbr < 0)
		{
			str[i] = '-';
			long_nbr *= -1;
			negative = 1;
		}
		else
		{
			str[i] = base[long_nbr % ft_strlen(base, 0, 0)];
			long_nbr /= ft_strlen(base, 0, 0);
		}
		i++;
	}
	return (ft_rev_int_tab(str, ft_strlen(str, 0, 0), negative));
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int			temp_dec;
	int			i;
	static char	null[1];

	i = 0;
	if (ft_strlen("", base_to, 1) || ft_strlen("", base_from, 1))
		return (0);
	temp_dec = ft_atoi_base(nbr, base_from);
	if (temp_dec == 0)
	{
		null[0] = base_to[0];
		return (null);
	}
	return (ft_int_to_base(temp_dec, base_to));
}
/*
int main(int argc, char **argv)
{
	printf("%s",ft_convert_base(argv[1], argv[2], argv[3]));
}
*/

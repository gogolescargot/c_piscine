/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 22:27:37 by ggalon            #+#    #+#             */
/*   Updated: 2023/08/16 22:27:39 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_power(int i, int n)
{
	int	temp;

	temp = i;
	if (n == 0)
		return (1);
	while (n > 1)
	{
		i *= temp;
		n--;
	}
	return (i);
}

int	ft_strstr(char *str, char to_find)
{
	int	i;
	int	o;

	i = 0;
	o = 0;
	if (to_find == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] == to_find)
			o += 1;
		i++;
	}
	return (o);
}

int	ft_strlen(char *str, char *base, int mode)
{
	int	i;

	i = 0;
	if (mode == 0)
	{
		while (str[i])
			i++;
		return (i);
	}
	if (ft_strlen(base, 0, 0) <= 1)
		return (1);
	if (ft_strstr(base, *("+")) || (ft_strstr(base, *("-"))))
		return (1);
	if (ft_strstr(base, *(" ")) || ft_strstr(base, *("\f")))
		return (1);
	if (ft_strstr(base, *("\n")) || ft_strstr(base, *("\r")))
		return (1);
	if (ft_strstr(base, *("\t")) || ft_strstr(base, *("\v")))
		return (1);
	while (i < ft_strlen(base, 0, 0))
	{
		if (ft_strstr(base, base[i++]) > 1)
			return (1);
	}
	return (0);
}

int	ft_ctoint(char *str, char *base)
{
	int	i;
	int	j;
	int	r;
	int	f;

	i = 1;
	j = 0;
	r = 0;
	f = ft_strlen(base, 0, 0);
	while (str[i])
	{
		while (base[j] != str[i])
			j++;
		r += j * ft_power(f, ft_strlen(str, 0, 0) - i - 1);
		i++;
		j = 0;
	}
	if (str[0] == *("-"))
		r *= -1;
	return (r);
}

int	ft_atoi_base(char *str, char *base)
{
	int		i;
	int		j;
	int		m;
	char	a[40];

	if (ft_strlen(base, base, 1))
		return (0);
	i = 0;
	j = 1;
	m = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			m++;
		i++;
	}
	a[0] = *("+");
	if (m % 2 != 0)
		a[0] = *("-");
	while (ft_strstr(base, str[i]))
		a[j++] = str[i++];
	a[j] = 0;
	return (ft_ctoint(a, base));
}
/*
#include <stdio.h>
int	main(int argc, char *argv[])
{
	printf("%d", ft_atoi_base(argv[1], argv[2]));
}
*/
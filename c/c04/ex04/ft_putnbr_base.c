/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 12:28:55 by ggalon            #+#    #+#             */
/*   Updated: 2023/08/17 15:41:02 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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

int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	ft_check_base(char *base)
{
	int	i;

	i = 0;
	if (ft_strlen(base) <= 1)
		return (1);
	if (ft_strstr(base, *("+")) || (ft_strstr(base, *("-"))))
		return (1);
	if (ft_strstr(base, *(" ")) || ft_strstr(base, *("\f")))
		return (1);
	if (ft_strstr(base, *("\n")) || ft_strstr(base, *("\r")))
		return (1);
	if (ft_strstr(base, *("\t")) || ft_strstr(base, *("\v")))
		return (1);
	while (i < ft_strlen(base))
	{
		if (ft_strstr(base, base[i++]) > 1)
			return (1);
	}
	return (0);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		i;

	i = 0;
	if (ft_check_base(base))
		return ;
	if (nbr == -2147483648)
	{
		write(1, "-", 1);
		ft_putnbr_base((unsigned int)nbr / ft_strlen(base), base);
		write(1, base + (unsigned int)-nbr % ft_strlen(base), 1);
		return ;
	}
	if (nbr < 0)
	{
		write(1, "-", 1);
		ft_putnbr_base(-nbr, base);
	}
	else if (nbr > ft_strlen(base) - 1)
	{
		ft_putnbr_base(nbr / ft_strlen(base), base);
		write(1, base + nbr % ft_strlen(base), 1);
		i++;
	}
	else
		write(1, base + nbr % ft_strlen(base), 1);
}
/*
int main(int argc, char *argv[])
{
	ft_putnbr_base(100,argv[1]);
}
*/

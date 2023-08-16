/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 12:28:55 by ggalon            #+#    #+#             */
/*   Updated: 2023/08/16 16:01:01 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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

void	ft_putnbr_base(int nbr, char *base)
{
	int		i;

	i = 0;
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

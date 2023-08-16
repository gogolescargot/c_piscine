/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 16:41:10 by ggalon            #+#    #+#             */
/*   Updated: 2023/08/14 16:50:41 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int				i;
	unsigned char	hex;
	char			*base;

	i = 0;
	base = "0123456789abcdef";
	while (str[i])
	{
		if (str[i] < 32 || str[i] == 127)
		{
			hex = str[i];
			ft_putchar('\\');
			write (1, base + (unsigned int)hex / 16, 1);
			write (1, base + (unsigned int)hex % 16, 1);
		}
		else
		{
			ft_putchar(str[i]);
		}
		i++;
	}
}

int main(void)
{
	char str[] = "test";
	str[3] = -1;
	ft_putstr_non_printable(str);
}

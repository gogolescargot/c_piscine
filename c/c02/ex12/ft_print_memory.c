/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 11:35:41 by ggalon            #+#    #+#             */
/*   Updated: 2023/08/14 16:18:03 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_text(char *str, int pad, int end)
{
	int	i;

	i = 0;
	while (i < 16 && str[i + pad])
	{
		if (str[i + pad] < 32 || str[i + pad] == 127)
			write(1, ".", 1);
		else
			write(1, &str[i + pad], 1);
		i++;
	}
	if (end)
		write(1, ".", 1);
}

void	ft_putnbr(unsigned long nb, int mode)
{
	int		i;
	char	*base;
	char	array[16];

	base = "0123456789abcdef";
	i = 0;
	while (i < mode)
	{
		array[mode - i - 1] = *(base + (nb % 16));
		nb /= 16;
		i++;
	}
	ft_print_text(array, 0, 0);
}

void	ft_print_hex(char *str, int pad, int end)
{
	int		i;

	i = 0;
	write(1, " ", 1);
	while (i < 16 && str[i + pad])
	{
		ft_putnbr(str[pad + i], 2);
		if (i % 2 == 1)
			write(1, " ", 1);
		i++;
	}
	if (end)
	{
		ft_print_text("00", 0, 0);
		write(1, " ", 1);
	}
	while (i + 1 < 16)
	{
		ft_print_text("  ", 0, 0);
		if (i % 2 == 1)
			write(1, " ", 1);
		i++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned long	addr_dec;
	int				end;

	if (size == 0)
		return (0);
	end = 0;
	i = 0;
	j = 0;
	addr_dec = (unsigned long)&addr;
	while (i <= size / 16)
	{
		ft_putnbr(addr_dec + 16 * i, 16);
		write(1, ":", 1);
		if (i == size / 16)
			end = 1;
		ft_print_hex(addr, i * 16, end);
		ft_print_text(addr, i * 16, end);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}

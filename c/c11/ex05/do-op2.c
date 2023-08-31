/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 14:30:05 by ggalon            #+#    #+#             */
/*   Updated: 2023/08/28 16:18:42 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb);
void	ft_putchar(char c);

int	sum(int i, int j)
{
	return (ft_putnbr(i + j), ft_putchar(10), 0);
}

int	subtract(int i, int j)
{
	return (ft_putnbr(i - j), ft_putchar(10), 0);
}

int	multiplication(int i, int j)
{
	return (ft_putnbr(i * j), ft_putchar(10), 0);
}

int	division(int i, int j)
{
	if (j == 0)
		return (write(1, "Stop : division by zero\n", 24), -1);
	return (ft_putnbr(i / j), ft_putchar(10), 0);
}

int	modulo(int i, int j)
{
	if (j == 0)
		return (write(1, "Stop : modulo by zero\n", 22), -1);
	return (ft_putnbr(i % j), ft_putchar(10), 0);
}

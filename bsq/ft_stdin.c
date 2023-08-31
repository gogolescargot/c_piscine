/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:26:02 by ggalon            #+#    #+#             */
/*   Updated: 2023/08/30 20:13:44 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft.h"

char	*flush_str(char *str, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		str[i] = 0;
	return (str);
}

char	*ft_fill_buff(char *buff, char *stin, char *stout, int i)
{
	int	size;

	size = 1024;
	while (size > 0)
	{
		flush_str(stin, 1024 + 1);
		size = read(0, stin, 1024);
		i++;
		if (stout)
			free(stout);
		stout = malloc(sizeof(char) * (i * 1024 + 1));
		flush_str(stout, i * 1024 + 1);
		ft_strncpy(stout, buff, 1024 * (i - 1));
		if (buff)
			free(buff);
		buff = malloc(sizeof(char) * (i * 1024 + 1));
		flush_str(buff, i * 1024 + 1);
		ft_strncat(stout, stin, 1024);
		ft_strncpy(buff, stout, i * 1024);
	}
	if (stin)
		free (stin);
	if (stin)
		free(buff);
	return (stout);
}

char	*ft_read_buff(void)
{
	int		i;
	char	*stin;
	char	*stout;
	char	*buff;

	i = 1;
	stout = NULL;
	stin = malloc(sizeof(char) * (1024 + 1));
	if (!stin)
		return (NULL);
	buff = malloc(sizeof(char) * (1024 + 1));
	if (!buff)
		return (NULL);
	flush_str(buff, 1024 + 1);
	stout = ft_fill_buff(buff, stin, stout, i);
	return (stout);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 23:47:59 by ggalon            #+#    #+#             */
/*   Updated: 2023/08/30 20:19:48 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft.h"

int	ft_size_file(char *file)
{
	int		fd;
	int		i;
	char	temp;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	while (1)
	{
		if (read(fd, &temp, 1 == -1))
		{
			close(fd);
			return (0);
		}
		else if (read(fd, &temp, 1) == 0)
			break ;
		else
			i++;
	}
	close(fd);
	return (i);
}

char	*ft_read_file(char *file)
{
	int		fd;
	char	*text;
	int		i;

	i = ft_size_file(file);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	text = malloc(sizeof(char) * (i + 1) + 1);
	if (!text)
	{
		close(fd);
		return (NULL);
	}
	if (read(fd, text, i) == -1 || !text)
	{
		free(text);
		close(fd);
		return (NULL);
	}
	text[i] = 0;
	close(fd);
	return (text);
}

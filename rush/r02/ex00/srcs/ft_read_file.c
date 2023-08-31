/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 01:55:54 by ggalon            #+#    #+#             */
/*   Updated: 2023/08/27 16:55:47 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int	ft_size_file(char *file)
{
	int		fd;
	int		i;
	char	temp;

	fd = open(file, O_RDONLY);
	while (1)
	{
		if (read(fd, &temp, 1 == -1))
			return (close(fd), 0);
		else if (read(fd, &temp, 1) == 0)
			break ;
		else
			i++;
	}
	close(fd);
	return (i + 1);
}

char	*ft_read_file(char *file)
{
	int		fd;
	char	*text;
	int		i;

	i = ft_size_file(file);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	text = malloc(sizeof(char) * (i + 1));
	if (!text)
		return (NULL);
	if (read(fd, text, i) == -1 || !text)
		return (0);
	text[i] = 0;
	close(fd);
	return (text);
}

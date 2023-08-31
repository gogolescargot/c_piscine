/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vigenere.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:48:27 by ggalon            #+#    #+#             */
/*   Updated: 2023/08/30 17:35:57 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

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
		close(fd);
		return (NULL);
	}
	text[i] = 0;
	close(fd);
	return (text);
}

int	ft_strlen(const char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*vigenere(char *text, const char *key)
{
	char	*alpha_lower;
	char	*alpha_upper;
	int		key_s;
	int		i;

	if (!text)
		return (NULL);
	alpha_lower = "abcdefghijklmnopqrstuvwxyz";
	alpha_upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	key_s = ft_strlen(key);
	i = -1;
	while (text[++i])
	{
		if (text[i] >= 'a' && text[i] <= 'z')
			text[i] = (text[i] + key[i % key_s] - 2 * 'a') % 26 + 'a';
		else if (text[i] >= 'A' && text[i] <= 'Z')
			text[i] = (text[i] + key[i % key_s] - 'a' - 'A') % 26 + 'A';
	}
	text[i] = 0;
	return (text);
}

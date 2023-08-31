/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:55:14 by ggalon            #+#    #+#             */
/*   Updated: 2023/08/30 20:22:32 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft.h"

void	ft_print_error(int argc)
{
	if (argc > 2)
		write(1, "map error\n\n", 11);
	else
		write(1, "map error\n", 10);
}

int	ft_check_forbidden(char *str_file, char *allowed_char)
{
	int	i;

	i = 0;
	while (allowed_char[i])
	{
		if (allowed_char[i] < 32 || allowed_char[i] > 126
			|| ft_strstr_occ(allowed_char, allowed_char[i]) > 1)
			return (-1);
		i++;
	}
	i = ft_get_eol(str_file) + 1;
	while (str_file[i])
	{
		if (ft_strstr_occ(allowed_char, str_file[i]) == 0)
			return (-1);
		i++;
	}
	return (0);
}

int	ft_check_map_stdin(char *str)
{
	char	*chars;
	int		trigger;

	if (!str)
		trigger = -1;
	chars = ft_get_char(str);
	if (chars == 0)
	{
		free(chars);
		return (-1);
	}
	trigger = 0;
	if (!str || ft_strlen(chars) != 3
		|| ft_check_forbidden(str, chars) == -1)
		trigger = -1;
	else if (ft_get_size(str) != ft_count_row(str)
		|| ft_count_row(str) != ft_count_column(str))
		trigger = -1;
	else if (ft_get_size(str) < 1 || ft_count_row(str) < 1
		|| ft_count_column(str) < 1)
		trigger = -1;
	free(chars);
	if (trigger == -1)
		return (-1);
	return (0);
}

int	ft_check_map(char *file, int argc)
{
	char	*str_file;
	char	*chars;
	int		trigger;

	str_file = ft_read_file(file);
	if (!str_file)
		return (ft_print_error(argc), -1);
	chars = ft_get_char(str_file);
	if (chars == 0)
		return (free(str_file), ft_print_error(argc), -1);
	trigger = 0;
	if (!str_file || ft_strlen(chars) != 3
		|| ft_check_forbidden(str_file, chars) == -1)
		trigger = -1;
	else if (ft_get_size(str_file) != ft_count_row(str_file)
		|| ft_count_row(str_file) != ft_count_column(str_file))
		trigger = -1;
	else if (ft_get_size(str_file) < 1 || ft_count_row(str_file) < 1
		|| ft_count_column(str_file) < 1)
		trigger = -1;
	free(str_file);
	free(chars);
	if (trigger == -1)
		return (ft_print_error(argc), -1);
	return (0);
}

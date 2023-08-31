/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dict1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 13:46:23 by ggalon            #+#    #+#             */
/*   Updated: 2023/08/27 17:09:55 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_char_printable(char c);
int	ft_strlen(char *str);
int	ft_count_nline(char *str);
int	ft_strstr(int size, char **str, char *to_find);

int	ft_check_duplicate(char *str, char **keys)
{
	int	i;

	i = 0;
	while (i < ft_count_nline(str))
	{
		if (ft_strstr(ft_count_nline(str), keys, keys[i]) > 1)
			return (-1);
		i++;
	}
	return (0);
}

int	ft_correct_synthax(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < ft_count_nline(str))
	{
		while (str[j] != ':' && str[j])
			j++;
		while (str[j] != '\n' && str[j])
			j++;
		if (str[j] != '\n')
			return (-1);
		i++;
	}
	return (0);
}

int	ft_correct_key(char *key)
{
	int	i;

	i = 0;
	while (key[i])
	{
		if (key[i] >= '0' && key[i] <= '9')
			return (0);
		i++;
	}
	return (-1);
}

int	ft_correct_value(char *value)
{
	int	i;

	i = 0;
	while (value[i])
	{
		if (ft_char_printable(value[i]))
			return (0);
		i++;
	}
	return (-1);
}

int	ft_check_dict(char *str, char **keys, char **values)
{
	int	i;

	i = 0;
	if (!str || ft_strlen(str) == 0)
		return (-1);
	while (i < ft_count_nline(str))
	{
		if (ft_correct_key(keys[i]) == -1)
			return (-1);
		if (ft_correct_value(values[i]) == -1)
			return (-1);
		i++;
	}
	return (0);
}

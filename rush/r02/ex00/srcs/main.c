/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 22:42:05 by ggalon            #+#    #+#             */
/*   Updated: 2023/08/27 16:56:04 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

char	*ft_read_file(char *file);
int		ft_check_dict(char *str, char **keys, char **values);
int		ft_correct_synthax(char *str);
int		ft_check_duplicate(char *str, char **keys);
char	**ft_init_keys(char *str);
char	**ft_init_values(char *str);
int		ft_count_nline(char *str);
char	*ft_trim(char *str);
char	**fill_array(int *array, int size);
char	*ft_atoa(char *str);
char	*ft_find_numbers(int size, char **keys, char**values, char *to_find);
void	ft_putstr(char *str);
int		ft_atoi(char *str);
int		*ft_int_decomp(int nb);
void	ft_putchar(char c);

int	main(int argc, char **argv)
{
	char	*dict;
	char	**keys;
	char	**values;
	int		i;

	i = -1;
	if (argc != 2)
		return (write(1, "Error\n", 6), -1);
	(void)argv;
	dict = ft_read_file("numbers.dict");
	if (ft_correct_synthax(dict) == -1)
		return (write(1, "Dict Error\n", 11), -1);
	keys = ft_init_keys(dict);
	values = ft_init_values(dict);
	while (++i < ft_count_nline(dict))
	{
		values[i] = ft_trim(values[i]);
		keys[i] = ft_atoa(keys[i]);
	}
	if (ft_check_duplicate(dict, keys) == -1)
		return (write(1, "Dict Error\n", 11), -1);
	if (ft_check_dict(dict, keys, values) == -1)
		return (write(1, "Dict Error\n", 11), -1);
}

/*
	printf("%s - %s\n", keys[i], values[i]);
	free(values);
	free(keys);
	free(dict);
	nb = fill_array(ft_int_decomp(ft_atoi(argv[1])), 4);
	while (i < 4)
	{
		ft_putstr((ft_find_numbers(ft_count_nline(dict), keys, values, nb[i])));
		ft_putchar(10);
		i++;
	}
*/

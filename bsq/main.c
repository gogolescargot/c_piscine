/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 00:06:05 by ggalon            #+#    #+#             */
/*   Updated: 2023/08/30 20:25:32 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft.h"

void	ft_free_main(char *str_file, char *chars, int **map, int size)
{
	free(str_file);
	free(chars);
	ft_free_array(map, size);
}

void	main2(int **map, char *str_file, char *chars, int argc)
{
	if (!map)
	{
		ft_print_error(argc);
		free(str_file);
		return ;
	}
	ft_square_map(map, ft_get_size(str_file), chars);
	if (argc > 2)
		write(1, "\n", 1);
	ft_free_main(str_file, chars, map, ft_get_size(str_file));
}

void	main3(void)
{
	char	*chars;
	int		**map;
	char	*str_in;

	str_in = ft_read_buff();
	if (ft_check_map_stdin(str_in) == -1)
	{
		free(str_in);
		write(1, "map error\n", 10);
		return ;
	}
	chars = ft_get_char(str_in);
	map = ft_create_map(str_in, ft_get_size(str_in), chars);
	main2(map, str_in, chars, 1);
}

int	main(int argc, char **argv)
{
	char	*str_file;
	char	*chars;
	int		i;
	int		**map;

	i = 0;
	if (argc == 1)
		main3();
	while (++i < argc)
	{
		if (ft_check_map(argv[i], argc) == -1)
			continue ;
		str_file = ft_read_file(argv[i]);
		if (!str_file)
		{
			ft_print_error(argc);
			continue ;
		}
		chars = ft_get_char(str_file);
		map = ft_create_map(str_file, ft_get_size(str_file), chars);
		main2(map, str_file, chars, argc);
	}
}

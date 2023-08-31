/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 14:03:33 by ggalon            #+#    #+#             */
/*   Updated: 2023/08/20 14:03:34 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	*init_array2(char **argv, int array[6][6])
{
	array[0][1] = argv[1][0];
	array[0][2] = argv[1][2];
	array[0][3] = argv[1][4];
	array[0][4] = argv[1][6];
	array[5][1] = argv[1][8];
	array[5][2] = argv[1][10];
	array[5][3] = argv[1][12];
	array[5][4] = argv[1][14];
	array[1][0] = argv[1][16];
	array[2][0] = argv[1][18];
	array[3][0] = argv[1][20];
	array[4][0] = argv[1][22];
	array[1][5] = argv[1][24];
	array[2][5] = argv[1][26];
	array[3][5] = argv[1][28];
	array[4][5] = argv[1][30];
	return (*array);
}

int	*init_array(char **argv, int array[6][6])
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (i++ < 5)
	{
		while (j++ < 5)
			array[i][j] = 0;
		j = -1;
	}
	return (init_array2(argv, array));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drafts.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matboyer <matboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 21:53:09 by matboyer          #+#    #+#             */
/*   Updated: 2023/08/27 13:46:27 by matboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

// free tout les maloc d'un pointeur de pointeur en partant de current_i
// et en remontant jusqu'a 0 pour eviter les leaks.
int	free_mallocs_iterative(char **to_free, int current_i)
{
	while (current_i > 0)
	{
		free (to_free[current_i]);
		current_i--;
	}
	return (0);
}

// recupere la taille d'une string
int	ft_str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

// je doit faire deux fonctions malloc car une seule etait trop grande
// celle ci est la secondaire
int	ft_sub_malloc(char **ptr, int len, int remaining_chars, char *nb_in_str)
{
	int	j;
	int	i;
	int	num_chunks;
	int	chunk_size;

	i = 0 ;
	num_chunks = (len + 2) / 3;
	while (i <= num_chunks - 1)
	{
		if (remaining_chars > 3)
			chunk_size = 3;
		else
			chunk_size = remaining_chars;
		ptr[i] = malloc((chunk_size + 1));
		if (!ptr[i])
			return (free_mallocs_iterative(ptr, i));
		j = -1;
		while (++j < chunk_size)
			ptr[i][j] = nb_in_str[len - chunk_size + j];
		len -= j;
		ptr[i][chunk_size] = '\0';
		i++;
		remaining_chars -= chunk_size;
	}
	return (1);
}

// je doit faire deux fonctions malloc car une seule etait trop grande 
// celle ci est la principale
// s'occupe de stoquer les char que retourne : split in weight
void	ft_malloc_numbers(char **ptr, char *nb_in_str)
{
	int	remaining_chars;
	int	len;
	int	num_chunks;

	len = ft_str_len(nb_in_str);
	num_chunks = (len + 2) / 3;
	remaining_chars = len;
	ptr = malloc((sizeof(char *) * (num_chunks + 1)));
	if (!ptr)
		return ;
	ft_sub_malloc(ptr, len, remaining_chars, nb_in_str);
	ptr[num_chunks] = NULL;
}

// declanche la fonction malloc_numbers et stoque la string
// nb in string dans un pointeur de pointeur 
// exemple : 12345678 retourne => [['1','2'],['3','4','5'],['6','7','8']]
char	**ft_split_in_weight(char **ptr, char *nb_in_str)
{
	ft_malloc_numbers(ptr, nb_in_str);
	return (ptr);
}

// int main()
// {
// 	char **test;
// 	test = NULL;
// 	ft_split_in_weight(test,"12345678");
// 	int i;
// 	i = 2;
// 	return (0);
// }
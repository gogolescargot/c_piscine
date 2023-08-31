/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:05:30 by ggalon            #+#    #+#             */
/*   Updated: 2023/08/30 20:29:10 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

void	ft_putchar(char c);
void	ft_print_error(int argc);
char	*ft_read_buff(void);
char	*ft_read_file(char *file);
char	*ft_get_char(char *str);
char	*ft_fill_buff(char *buff, char *stin, char *stout, int i);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
char	*ft_strncat(char *dest, char *src, unsigned int nb);
int		ft_atoi(char *str);
int		ft_strlen(char *str);
int		ft_get_size(char *str);
int		ft_get_eol(char *str);
int		ft_count_row(char *str);
int		ft_count_column(char *str);
int		ft_strstr_occ(char *str, char to_find);
int		ft_strstr_ind(char *str, char to_find);
int		**ft_create_map(char *str_file, int size, char *chars);
int		ft_square_map(int **tab, int size, char *chars);
int		ft_check_map(char *file, int argc);
int		ft_check_map_stdin(char *str);
int		**ft_free_array(int **map, int size);

#endif
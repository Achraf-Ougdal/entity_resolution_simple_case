/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aougdal <aougdal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 03:44:36 by aougdal           #+#    #+#             */
/*   Updated: 2019/10/24 16:16:13 by aougdal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdbool.h>
#include <ctype.h>

# define BUFFER_SIZE 32

char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
void			free_array(char	**tab_to_free, int size);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
int				is_line_empty(char *line);
size_t			ft_max(size_t a, size_t b);
size_t			ft_min(size_t a, size_t b);
char 			*ft_strndup(const char *s, size_t n);
int				*characters_count(char *file_name);
int    			line_count(char *file_name);
int				get_next_line(int fd, char **line);
int     		levenshtein(const char *s, int ls, const char *t, int lt);
double			JaroWinkler(const char *str1, const char *str2);
double 			ngram_distance(const char *source, const char *target, int n);
const char* 	soundex(const char *s);
void 			init();
void 			add_code(const char *s, int c);

#endif

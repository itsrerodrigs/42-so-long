/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: renrodri <renrodri@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:34:23 by renrodri          #+#    #+#             */
/*   Updated: 2025/04/28 22:24:21 by renrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define UPPER_HEX "0123456789ABCDEF"
# define LOWER_HEX "0123456789abcdef"

int		ft_strlen(char *s);
char	*ft_strchr(char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_itoa(int n);
char	*get_next_line(int fd);
int		ft_printf(const char *str, ...);
int		print_char(char c);
int		print_str(char *str);
int		print_ptr(unsigned long nbr, char *base);
int		print_nbr(int nbr, char *str, int index, int flag_check);
int		print_unint(unsigned int nbr);
int		print_hex(unsigned int nbr, char *str, int index, int hash_check);

#endif
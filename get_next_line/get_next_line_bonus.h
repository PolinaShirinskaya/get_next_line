/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 18:22:52 by adian             #+#    #+#             */
/*   Updated: 2021/12/29 18:38:05 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# ifndef OPEN_MAX
# endif
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif
# if BUFFER_SIZE < 0
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
char	*ft_strcpy(char *dst, const char *src);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strdup(const char *str);
char	*ft_strjoin(char *str1, char const *str2);
char	*get_next_line(int fd);
#endif

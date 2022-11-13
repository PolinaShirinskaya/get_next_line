/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 14:20:22 by adian             #+#    #+#             */
/*   Updated: 2021/12/29 18:38:05 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str && str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)(c))
			return ((char *)(s));
		s++;
	}
	return (NULL);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (!dest && !src)
		return (NULL);
	d = dest;
	s = src;
	while (n-- > 0)
		*d++ = *s++;
	return (dest);
}

char	*ft_strdup(const char *str)
{
	unsigned char	*s;
	int				str_len;

	str_len = ft_strlen(str) + 1;
	s = (unsigned char *)malloc(str_len * sizeof(char));
	if (s != NULL)
	{
		ft_memcpy(s, str, str_len);
		return ((char *)(s));
	}
	return (NULL);
}

char	*ft_strjoin(char *str1, char const *str2)
{
	size_t	str1_len;
	size_t	str2_len;
	size_t	cat_len;
	char	*str_cat;

	if (!str1 && !str2)
		return (NULL);
	if (str1 && !str2)
		return (ft_strdup(str1));
	if (!str1 && str2)
		return (ft_strdup(str2));
	str1_len = ft_strlen(str1);
	str2_len = ft_strlen(str2);
	cat_len = str1_len + str2_len + 1;
	str_cat = malloc(sizeof(char) * cat_len);
	if (str_cat != NULL)
	{
		ft_memcpy(str_cat, str1, str1_len);
		ft_memcpy(str_cat + str1_len, str2, str2_len);
		str_cat[cat_len - 1] = '\0';
		free (str1);
		return (str_cat);
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 20:10:04 by adian             #+#    #+#             */
/*   Updated: 2021/12/29 18:38:04 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_find_n(char *remains)
{
	int	i;

	i = 0;
	while (remains && remains[i])
	{
		if (remains[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_return(char *remains)
{
	char	*ret_line;
	int		i;

	i = 0;
	if (!remains || remains[0] == '\0')
		return (NULL);
	while (remains[i] != '\n' && remains[i] != '\0')
		i++;
	if (remains[i] == '\n')
		i++;
	ret_line = malloc(sizeof(char) * (i + 1));
	if (!ret_line)
		return (NULL);
	i = 0;
	while (remains[i] != '\n' && remains[i] != '\0')
	{
		ret_line[i] = remains[i];
		i++;
	}
	if (remains[i] == '\n')
		ret_line[i++] = '\n';
	ret_line[i] = '\0';
	return (ret_line);
}

static char	*ft_save(char *remains)
{
	char	*save_line;
	int		i;
	int		j;

	i = 0;
	while (remains && remains[i] != '\n' && remains[i] != '\0')
		i++;
	if (remains == NULL || remains[i] == '\0')
	{
		free (remains);
		return (NULL);
	}
	save_line = malloc(sizeof(char) * (ft_strlen(remains) - i));
	if (!save_line)
		return (NULL);
	i++;
	j = 0;
	while (remains[i] != '\0')
		save_line[j++] = remains[i++];
	save_line[j] = '\0';
	free(remains);
	return (save_line);
}

static char	*free_buff(char *buff)
{
	free (buff);
	buff = NULL;
	return (buff);
}

char	*get_next_line(int fd)
{
	static char	*remains;
	char		*ret_line;
	char		*buff;
	int			byte_read;

	if (fd > OPEN_MAX || fd < 0)
		return (NULL);
	byte_read = 1;
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	while (byte_read > 0 && !ft_find_n(remains))
	{
		byte_read = read(fd, buff, BUFFER_SIZE);
		if (byte_read < 0)
			return (free_buff(buff));
		buff[byte_read] = '\0';
		remains = ft_strjoin(remains, buff);
	}
	free_buff(buff);
	ret_line = ft_return(remains);
	remains = ft_save(remains);
	return (ret_line);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eluceon <eluceon@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 14:30:07 by eluceon           #+#    #+#             */
/*   Updated: 2021/04/26 18:07:06 by eluceon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	free_and_null(char **str, int ret_value)
{
	if (str)
	{
		free(*str);
		*str = NULL;
	}
	return (ret_value);
}

int	ft_return(int n_read, char **line, char *p_nl, char **remainder)
{
	if (n_read < 0 || !(*line))
	{
		free_and_null(remainder, 0);
		return (free_and_null(line, -1));
	}
	else if (n_read || p_nl)
		return (1);
	else
		return (free_and_null(remainder, 0));
}

/*
** The function checks for a remainder. If the remainder exists then function
** checks for a line break. If the remainder does not exist or there is no
** line break in the remainder then find_remainder returns NULL.
*/

char	*find_remainder(char **line, char *remainder)
{
	char	*p_nl;

	p_nl = NULL;
	if (remainder)
	{
		p_nl = ft_strchr(remainder, '\n');
		if (p_nl)
		{
			*p_nl = '\0';
			*line = ft_strdup(remainder);
			remainder = ft_strcpy(remainder, ++p_nl);
		}
		else
		{
			*line = ft_strdup(remainder);
			remainder[0] = '\0';
		}
	}
	else
	{
		(*line = (char *)malloc(sizeof(char)));
		if (*line)
			*line[0] = '\0';
	}
	return (p_nl);
}

/*
** The function checks for a line break in buffer during reading. If there is
** no line break in the buffer then function returns NULL.
*/

char	*newline_in_buffer(char *buffer, char **remainder)
{
	char	*p_nl;

	p_nl = NULL;
	p_nl = ft_strchr(buffer, '\n');
	if (p_nl)
	{
		*p_nl = '\0';
		free_and_null(remainder, 0);
		*remainder = ft_strdup(++p_nl);
	}
	return (p_nl);
}

int	get_next_line(int fd, char **line)
{
	int			n_read;
	char		buffer[BUFFER_SIZE + 1];
	static char	*remainder;
	char		*p_nl;
	char		*tmp;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	p_nl = find_remainder(line, remainder);
	if (!(*line))
		return (free_and_null(&remainder, -1));
	n_read = 0;
	while (!p_nl)
	{
		n_read = read(fd, buffer, BUFFER_SIZE);
		if (n_read <= 0)
			break ;
		buffer[n_read] = '\0';
		p_nl = newline_in_buffer(buffer, &remainder);
		tmp = *line;
		*line = ft_strjoin(*line, buffer);
		free(tmp);
	}
	return (ft_return(n_read, line, p_nl, &remainder));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_numbers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eluceon <eluceon@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 21:03:49 by eluceon           #+#    #+#             */
/*   Updated: 2021/05/06 23:38:15 by eluceon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int	is_integer(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' && str[i + 1] >= '0' && str[i + 1] <= '9')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		if ((i > 11 && str[0] == '-') || (i > 10 && str[0] != '-'))
			return (0);
		i++;
	}
	if (str[0] == '-' && i == 11 && ft_strncmp(str, MIN_INT, i) > 0)
		return (0);
	else if (str[0] != '-' && i == 10 && ft_strncmp(str, MAX_INT, i) > 0)
		return (0);
	return (1);
}

int	is_space(char	*str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] != ' ' || str[i] != '\t')
			return (0);
	}
	return (1);
}

char	*split_argv(const char *orig_str, int *i, t_nbr_list **head, char **str)
{
	int		start_inx;
	int		j;

	while (orig_str[*i] && (orig_str[*i] == ' ' || orig_str[*i] == '\t'))
		(*i)++;
	start_inx = *i;
	while (orig_str[*i] && (orig_str[*i] != ' ' && orig_str[*i] != '\t'))
		(*i)++;
	if (*i == start_inx)
		return (NULL);
	*str = (char *)malloc(*i - start_inx + 1);
	if (!(*str))
		exit_error_free(head);
	j = -1;
	while (start_inx < *i)
		(*str)[++j] = orig_str[start_inx++];
	(*str)[++j] = '\0';
	return (*str);
}

void	check_integers(char **argv, int start_arg)
{
	char	*tmp_str;
	int		j;

	while (argv[++start_arg])
	{
		j = 0;
		while ((split_argv(argv[start_arg], &j, NULL, &tmp_str)))
		{
			if (!is_integer(tmp_str) && (!is_space(tmp_str)))
			{
				free(tmp_str);
				ft_putstr_fd("Error\n", 2);
				exit(1);
			}
			free(tmp_str);
		}
	}
}

void	get_numbers(char **argv, t_nbr_list **head, int *a_len)
{
	int			i;
	int			j;
	t_nbr_list	*new_element;
	char		*tmp_str;

	i = 0;
	while (argv[++i])
	{
		j = 0;
		while ((split_argv(argv[i], &j, head, &tmp_str)))
		{
			new_element = new_nbr_list(ft_atoi(tmp_str));
			free(tmp_str);
			if (!new_element)
				exit_error_free(head);
			append_nbr_list(head, new_element);
		}
	}
	*a_len = nbr_listsize(*head);
}

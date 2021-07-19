/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eluceon <eluceon@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 14:54:39 by eluceon           #+#    #+#             */
/*   Updated: 2021/04/25 12:51:49 by eluceon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	clear_cmd_list(t_command_list **cmd_lst)
{
	t_command_list	*tmp1;
	t_command_list	*tmp2;

	if (*cmd_lst)
	{
		tmp1 = *cmd_lst;
		while (tmp1)
		{
			tmp2 = tmp1->next;
			free(tmp1->command);
			tmp1->command = NULL;
			free(tmp1);
			tmp1 = NULL;
			tmp1 = tmp2;
		}
		*cmd_lst = NULL;
	}
}

int	check_command_names(char *line)
{
	if (!ft_strncmp("sa", line, 3))
		return (1);
	else if (!ft_strncmp("sb", line, 3))
		return (1);
	else if (!ft_strncmp("ss", line, 3))
		return (1);
	else if (!ft_strncmp("ra", line, 3))
		return (1);
	else if (!ft_strncmp("rb", line, 3))
		return (1);
	else if (!ft_strncmp("rr", line, 3))
		return (1);
	else if (!ft_strncmp("rra", line, 4))
		return (1);
	else if (!ft_strncmp("rrb", line, 4))
		return (1);
	else if (!ft_strncmp("rrr", line, 4))
		return (1);
	else if (!ft_strncmp("pa", line, 3))
		return (1);
	else if (!ft_strncmp("pb", line, 3))
		return (1);
	return (0);
}

t_command_list	*new_cmd_list(t_ps *ps, char *cmd)
{
	t_command_list	*cmd_new;

	cmd_new = (t_command_list *)malloc(sizeof(t_command_list));
	if (!cmd_new)
	{
		clear_cmd_list(&ps->cmd_head);
		exit_error_free(&ps->a.head);
	}
	cmd_new->next = NULL;
	cmd_new->command = cmd;
	return (cmd_new);
}

void	append_cmd_list(t_command_list **head, t_command_list *cmd_new)
{
	t_command_list	*tmp;

	tmp = *head;
	if (!*head)
		(*head) = cmd_new;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = cmd_new;
	}
}

void	get_commands(t_ps *ps)
{
	char			*line;

	while ((get_next_line(0, &line)))
	{
		if (!check_command_names(line))
		{
			free(line);
			exit_error_free(&ps->a.head);
		}
		append_cmd_list(&ps->cmd_head, new_cmd_list(ps, line));
	}
	if (ft_strncmp("", line, 1) && !check_command_names(line))
	{
		free(line);
		exit_error_free(&ps->a.head);
	}
	append_cmd_list(&ps->cmd_head, new_cmd_list(ps, line));
}

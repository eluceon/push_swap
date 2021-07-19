/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_linked_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eluceon <eluceon@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 19:31:19 by eluceon           #+#    #+#             */
/*   Updated: 2021/05/06 18:20:12 by eluceon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int	nbr_listsize(t_nbr_list *head)
{
	int			size;
	t_nbr_list	*tmp;

	if (head)
	{
		size = 1;
		tmp = head;
		while (tmp != head->prev)
		{
			tmp = tmp->next;
			size++;
		}
		return (size);
	}
	return (0);
}

t_nbr_list	*new_nbr_list(int nbr)
{
	t_nbr_list	*new;

	new = (t_nbr_list *)malloc(sizeof(t_nbr_list));
	if (!new)
		return (NULL);
	new->next = new;
	new->prev = new;
	new->nbr = nbr;
	return (new);
}

void	append_nbr_list(t_nbr_list **head, t_nbr_list *new)
{
	t_nbr_list	*tmp;

	tmp = *head;
	if (!new)
		exit_error_free(head);
	else if (!*head)
		(*head) = new;
	else
	{
		while ((tmp->next != *head) || (new->nbr == (*head)->nbr))
		{
			if (new->nbr == tmp->nbr)
			{
				free(new);
				exit_error_free(head);
			}
			tmp = tmp->next;
		}
		(*head)->prev = new;
		new->next = tmp->next;
		new->prev = tmp;
		tmp->next = new;
	}
}

void	nbr_list_clear(t_nbr_list **head)
{
	t_nbr_list	*tmp1;
	t_nbr_list	*tmp2;

	if (*head)
	{
		tmp1 = (*head)->next;
		while (tmp1 && tmp1 != *head)
		{
			tmp2 = tmp1->next;
			free(tmp1);
			tmp1 = NULL;
			tmp1 = tmp2;
		}
		free(*head);
		*head = NULL;
	}
}

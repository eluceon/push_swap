/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eluceon <eluceon@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 16:55:05 by eluceon           #+#    #+#             */
/*   Updated: 2021/04/25 18:16:27 by eluceon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	take_first_element(t_stack *stack)
{
	if (stack->head == stack->head->next)
		stack->head = NULL;
	else
	{
		stack->head->prev->next = stack->head->next;
		stack->head->next->prev = stack->head->prev;
		stack->head = stack->head->next;
	}
}

void	put_at_top_of_another_stack(t_nbr_list *tmp, t_stack *stack)
{
	if (stack->head)
	{
		tmp->next = stack->head;
		tmp->prev = stack->head->prev;
		stack->head->prev = tmp;
		tmp->prev->next = tmp;
		stack->head = stack->head->prev;
	}
	else
	{
		stack->head = tmp;
		stack->head->next = stack->head;
		stack->head->prev = stack->head;
	}
}

void	do_pb(t_ps *ps)
{
	t_nbr_list	*tmp;

	if (ps->a.head)
	{
		tmp = ps->a.head;
		take_first_element(&ps->a);
		put_at_top_of_another_stack(tmp, &ps->b);
		ps->a.len -= 1;
		ps->b.len += 1;
	}
	option_print(ps, "pb", COLOR_FIRST_B);
}

void	do_pa(t_ps *ps)
{
	t_nbr_list	*tmp;

	if (ps->b.head)
	{
		tmp = ps->b.head;
		take_first_element(&ps->b);
		put_at_top_of_another_stack(tmp, &ps->a);
		ps->b.len -= 1;
		ps->a.len += 1;
	}
	option_print(ps, "pa", COLOR_FIRST_A);
}

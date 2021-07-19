/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eluceon <eluceon@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 08:44:11 by eluceon           #+#    #+#             */
/*   Updated: 2021/04/25 17:23:08 by eluceon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	do_sa(t_ps *ps, int print_cmd)
{
	t_nbr_list	*tmp;

	if (ps->a.head)
	{
		tmp = ps->a.head;
		ps->a.head = ps->a.head->next;
		tmp->next = ps->a.head->next;
		ps->a.head->next->prev = tmp;
		ps->a.head->prev = tmp->prev;
		ps->a.head->next = tmp;
		tmp->prev->next = ps->a.head;
		tmp->prev = ps->a.head;
	}
	if (print_cmd)
		option_print(ps, "sa", COLOR_FIRST_A + COLOR_SECOND_A);
}

void	do_sb(t_ps *ps, int print_cmd)
{
	t_nbr_list	*tmp;

	if (ps->b.head)
	{
		tmp = ps->b.head;
		ps->b.head = ps->b.head->next;
		tmp->next = ps->b.head->next;
		ps->b.head->next->prev = tmp;
		ps->b.head->prev = tmp->prev;
		ps->b.head->next = tmp;
		tmp->prev->next = ps->b.head;
		tmp->prev = ps->b.head;
	}
	if (print_cmd)
		option_print(ps, "sb", COLOR_FIRST_B + COLOR_SECOND_B);
}

void	do_ss(t_ps *ps)
{
	do_sa(ps, NO_CMD_NAME);
	do_sb(ps, NO_CMD_NAME);
	option_print(ps, "ss", COLOR_FIRST_A + COLOR_SECOND_A
		+ COLOR_FIRST_B + COLOR_SECOND_B);
}

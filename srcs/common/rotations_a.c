/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eluceon <eluceon@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 16:21:37 by eluceon           #+#    #+#             */
/*   Updated: 2021/04/25 17:20:43 by eluceon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	do_ra(t_ps	*ps)
{
	if (ps->a.head)
		ps->a.head = ps->a.head->next;
	option_print(ps, "ra", COLOR_LAST_A);
}

void	do_rr(t_ps	*ps)
{
	if (ps->a.head)
		ps->a.head = ps->a.head->next;
	if (ps->b.head)
		ps->b.head = ps->b.head->next;
	option_print(ps, "rr", COLOR_LAST_A + COLOR_LAST_B);
}

void	do_rra(t_ps *ps)
{
	if (ps->a.head)
		ps->a.head = ps->a.head->prev;
	option_print(ps, "rra", COLOR_FIRST_A);
}

void	do_rrr(t_ps *ps)
{
	if (ps->a.head)
		ps->a.head = ps->a.head->prev;
	if (ps->b.head)
		ps->b.head = ps->b.head->prev;
	option_print(ps, "rrr", COLOR_FIRST_A + COLOR_FIRST_B);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eluceon <eluceon@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 17:18:33 by eluceon           #+#    #+#             */
/*   Updated: 2021/04/25 17:20:47 by eluceon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	do_rb(t_ps	*ps)
{
	if (ps->b.head)
		ps->b.head = ps->b.head->next;
	option_print(ps, "rb", COLOR_LAST_B);
}

void	do_rrb(t_ps *ps)
{
	if (ps->b.head)
		ps->b.head = ps->b.head->prev;
	option_print(ps, "rrb", COLOR_FIRST_B);
}

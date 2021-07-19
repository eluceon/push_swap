/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_short_stacks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eluceon <eluceon@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 09:31:48 by eluceon           #+#    #+#             */
/*   Updated: 2021/04/25 11:25:18 by eluceon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	sort_three_numbers_in_stack(t_ps *ps)
{
	if (ps->a.head->prev->nbr > ps->a.head->nbr
		&& ps->a.head->nbr > ps->a.head->next->nbr)
		do_sa(ps, PRINT_CMD_NAME);
	else if (ps->a.head->nbr > ps->a.head->next->nbr
		&& ps->a.head->next->nbr > ps->a.head->prev->nbr)
	{
		do_sa(ps, PRINT_CMD_NAME);
		do_rra(ps);
	}
	else if (ps->a.head->nbr > ps->a.head->prev->nbr
		&& ps->a.head->prev->nbr > ps->a.head->next->nbr)
		do_ra(ps);
	else if (ps->a.head->next->nbr > ps->a.head->prev->nbr
		&& ps->a.head->prev->nbr > ps->a.head->nbr)
	{
		do_sa(ps, PRINT_CMD_NAME);
		do_ra(ps);
	}
	else if (ps->a.head->next->nbr > ps->a.head->nbr
		&& ps->a.head->nbr > ps->a.head->prev->nbr)
		do_rra(ps);
}

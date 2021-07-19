/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_or_less_numbers.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eluceon <eluceon@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 09:14:03 by eluceon           #+#    #+#             */
/*   Updated: 2021/04/27 16:40:59 by eluceon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two_numbers_a(t_ps *ps, int len)
{
	if (len == 2)
	{
		if (ps->a.head->nbr > ps->a.head->next->nbr)
			do_sa(ps, PRINT_CMD_NAME);
	}
}

void	sort_two_numbers_b(t_ps *ps, int len)
{
	if (len == 1)
		do_pa(ps);
	else if (len == 2)
	{
		if (ps->b.head->nbr < ps->b.head->next->nbr)
			do_sb(ps, PRINT_CMD_NAME);
		do_pa(ps);
		do_pa(ps);
	}
}

void	sort_three_or_less_numbers_a(t_ps *ps, int len)
{
	if (len == 2)
		sort_two_numbers_a(ps, len);
	else if (len == 3 && ps->a.len == 3)
		sort_three_numbers_in_stack(ps);
	else if (len == 3)
	{
		while (len != 3 || !(ps->a.head->nbr < ps->a.head->next->nbr
				&& ps->a.head->next->nbr < ps->a.head->next->next->nbr))
		{
			if (len == 3 && ps->a.head->nbr > ps->a.head->next->nbr)
				do_sa(ps, PRINT_CMD_NAME);
			else if (len == 3)
			{
				do_pb(ps);
				len--;
			}
			else if (ps->a.head->nbr > ps->a.head->next->nbr)
				do_sa(ps, PRINT_CMD_NAME);
			else
			{
				do_pa(ps);
				len++;
			}
		}
	}
}

void	sort_push_three_or_less_numbers_b(t_ps *ps, int len)
{
	if (len == 1)
		do_pa(ps);
	else if (len == 2)
		sort_two_numbers_b(ps, len);
	else if (len == 3)
	{
		while (len || !(ps->a.head->nbr < ps->a.head->next->nbr
				&& ps->a.head->next->nbr < ps->a.head->next->next->nbr))
		{
			if (len == 1 && ps->a.head->nbr > ps->a.head->next->nbr)
				do_sa(ps, PRINT_CMD_NAME);
			if (len == 1 || (ps->b.head->nbr > ps->b.head->next->nbr))
			{
				do_pa(ps);
				len--;
			}
			else
				do_sb(ps, PRINT_CMD_NAME);
		}
	}
}

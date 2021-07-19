/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eluceon <eluceon@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 07:10:28 by eluceon           #+#    #+#             */
/*   Updated: 2021/05/06 19:00:09 by eluceon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_and_push_a(t_ps *ps, int len)
{
	int	rotation_counter;
	int	old_len;

	rotation_counter = 0;
	old_len = len;
	while (len > old_len / 2 + old_len % 2)
	{
		if (ps->a.head->nbr < ps->a.median && len)
		{
			len--;
			do_pb(ps);
		}
		else
		{
			rotation_counter++;
			do_ra(ps);
		}
	}
	while (ps->a.len > old_len / 2 + old_len % 2 && rotation_counter)
	{
		rotation_counter--;
		do_rra(ps);
	}
}

int	sort_stack_a(t_ps *ps, int len)
{
	if (is_sorted(ps->a, len, ASC_ORDER))
		return (1);
	if (len <= 3)
	{
		sort_three_or_less_numbers_a(ps, len);
		return (1);
	}
	if (!get_median(&ps->a.median, &ps->a, len))
		exit_error_all(ps);
	sort_and_push_a(ps, len);
	return (sort_stack_a(ps, len / 2 + len % 2)
		&& sort_stack_b(ps, len / 2));
	return (1);
}

void	sort_and_push_b(t_ps *ps, int len)
{
	int	old_len;
	int	rotation_counter;

	old_len = len;
	rotation_counter = 0;
	while (len > old_len / 2)
	{
		if (ps->b.head->nbr >= ps->b.median && len)
		{
			len--;
			do_pa(ps);
		}
		else
		{
			rotation_counter++;
			do_rb(ps);
		}
	}
	while (ps->b.len > old_len / 2 && rotation_counter)
	{
		rotation_counter--;
		do_rrb(ps);
	}
}

int	sort_stack_b(t_ps *ps, int len)
{
	if (is_sorted(ps->b, len, DESC_ORDER))
		while (len--)
			do_pa(ps);
	if (len <= 3)
	{
		sort_push_three_or_less_numbers_b(ps, len);
		return (1);
	}
	if (!get_median(&ps->b.median, &ps->b, len))
		exit_error_all(ps);
	sort_and_push_b(ps, len);
	return (sort_stack_a(ps, len / 2 + len % 2)
		&& sort_stack_b(ps, len / 2));
	return (1);
}

int	main(int argc, char **argv)
{
	t_ps	ps;

	if (argc == 1)
		exit_error();
	init_ps(&ps);
	check_integers(argv, check_options(&ps.options, argv[1]));
	ps.options = ps.options | PRINT_CMD_NAME;
	if (ps.options & FLAG_COLOR || ps.options & FLAG_STACK_STATUS)
		get_numbers(argv + 1, &ps.a.head, &ps.a.len);
	else
		get_numbers(argv, &ps.a.head, &ps.a.len);
	option_print(&ps, NULL, 0);
	sort_stack_a(&ps, ps.a.len);
	nbr_list_clear(&ps.a.head);
	nbr_list_clear(&ps.b.head);
	return (0);
}

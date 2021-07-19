/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eluceon <eluceon@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 11:16:30 by eluceon           #+#    #+#             */
/*   Updated: 2021/05/06 18:53:28 by eluceon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	cmd_manager(t_ps *ps, char *cmd_name)
{
	if (!ft_strncmp("sa", cmd_name, 3))
		do_sa(ps, PRINT_CMD_NAME);
	else if (!ft_strncmp("sb", cmd_name, 3))
		do_sb(ps, PRINT_CMD_NAME);
	else if (!ft_strncmp("ss", cmd_name, 3))
		do_ss(ps);
	else if (!ft_strncmp("ra", cmd_name, 3))
		do_ra(ps);
	else if (!ft_strncmp("rb", cmd_name, 3))
		do_rb(ps);
	else if (!ft_strncmp("rr", cmd_name, 3))
		do_rr(ps);
	else if (!ft_strncmp("rra", cmd_name, 4))
		do_rra(ps);
	else if (!ft_strncmp("rrb", cmd_name, 4))
		do_rrb(ps);
	else if (!ft_strncmp("rrr", cmd_name, 4))
		do_rrr(ps);
	else if (!ft_strncmp("pa", cmd_name, 3))
		do_pa(ps);
	else if (!ft_strncmp("pb", cmd_name, 3))
		do_pb(ps);
}

int	main(int argc, char **argv)
{
	t_ps			ps;
	t_command_list	*tmp;

	if (argc == 1)
		return (0);
	check_integers(argv, 0);
	init_ps(&ps);
	get_numbers(argv, &ps.a.head, &ps.a.len);
	get_commands(&ps);
	tmp = ps.cmd_head;
	while (tmp->next != NULL)
	{
		cmd_manager(&ps, tmp->command);
		tmp = tmp->next;
	}
	cmd_manager(&ps, tmp->command);
	clear_cmd_list(&ps.cmd_head);
	if (is_sorted(ps.a, ps.a.len, ASC_ORDER))
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	nbr_list_clear(&ps.a.head);
	nbr_list_clear(&ps.b.head);
	return (1);
}

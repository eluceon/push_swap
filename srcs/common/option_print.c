/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eluceon <eluceon@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 20:51:42 by eluceon           #+#    #+#             */
/*   Updated: 2021/04/25 17:15:42 by eluceon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	print_color_nbr(int	nbr)
{
	ft_putstr_fd("\033[1;32m", 1);
	ft_putnbr_fd(nbr, 1);
	ft_putstr_fd("\033[0;m", 1);
}

void	print_stack_a(t_stack stack_a, int col_elem)
{
	t_nbr_list	*tmp;

	write(1, "STACK A:\t", 9);
	if (stack_a.head)
	{
		tmp = stack_a.head;
		while (tmp->next != stack_a.head)
		{
			if ((tmp == stack_a.head && col_elem & COLOR_FIRST_A)
				|| (tmp->prev == stack_a.head && col_elem & COLOR_SECOND_A))
				print_color_nbr(tmp->nbr);
			else
				ft_putnbr_fd(tmp->nbr, 1);
			write(1, " ", 1);
			tmp = tmp->next;
		}
		if ((stack_a.head->next == stack_a.head
				&& (col_elem & COLOR_FIRST_A)) || col_elem & COLOR_LAST_A
			|| (tmp->prev == stack_a.head && col_elem & COLOR_SECOND_A))
			print_color_nbr(tmp->nbr);
		else
			ft_putnbr_fd(tmp->nbr, 1);
	}
	write(1, "\n", 1);
}

void	print_stack_b(t_stack stack_b, int col_elem)
{
	t_nbr_list	*tmp;

	write(1, "STACK B:\t", 9);
	if (stack_b.head)
	{
		tmp = stack_b.head;
		while (tmp->next != stack_b.head)
		{
			if ((tmp == stack_b.head && col_elem & COLOR_FIRST_B)
				|| (tmp->prev == stack_b.head && col_elem & COLOR_SECOND_B))
				print_color_nbr(tmp->nbr);
			else
				ft_putnbr_fd(tmp->nbr, 1);
			write(1, " ", 1);
			tmp = tmp->next;
		}
		if ((stack_b.head->next == stack_b.head
				&& (col_elem & COLOR_FIRST_B)) || col_elem & COLOR_LAST_B
			|| (tmp->prev == stack_b.head && col_elem & COLOR_SECOND_B))
			print_color_nbr(tmp->nbr);
		else
			ft_putnbr_fd(tmp->nbr, 1);
	}
	write(1, "\n", 1);
}

void	option_print(t_ps *ps, char *cmd_name, int color_element)
{
	if (cmd_name && ps->options & FLAG_COLOR)
	{
		ft_putstr_fd("\033[1;32m", 1);
		ft_putendl_fd(cmd_name, 1);
		ft_putstr_fd("\033[0;m", 1);
	}
	else if (cmd_name && ps->options & PRINT_CMD_NAME)
	{
		color_element = 0;
		ft_putendl_fd(cmd_name, 1);
	}
	if (ps->options & FLAG_STACK_STATUS)
	{
		print_stack_a(ps->a, color_element);
		print_stack_b(ps->b, color_element);
		ft_putendl_fd("________", 1);
	}
}

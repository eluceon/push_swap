/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eluceon <eluceon@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 20:59:09 by eluceon           #+#    #+#             */
/*   Updated: 2021/04/25 17:23:49 by eluceon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	exit_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	exit_error_free(t_nbr_list	**head)
{
	nbr_list_clear(head);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	exit_error_all(t_ps *ps)
{
	if (ps->a.head)
		nbr_list_clear(&ps->a.head);
	if (ps->b.head)
		nbr_list_clear(&ps->b.head);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

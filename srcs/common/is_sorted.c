/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eluceon <eluceon@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 17:33:18 by eluceon           #+#    #+#             */
/*   Updated: 2021/04/25 17:13:32 by eluceon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int	is_sorted(t_stack stack, int len, int order)
{
	t_nbr_list	*tmp;
	int			i;

	i = -1;
	tmp = stack.head;
	while (++i < len - 1)
	{
		if (order == ASC_ORDER && tmp->nbr > tmp->next->nbr)
			return (0);
		else if (order == DESC_ORDER && tmp->nbr < tmp->next->nbr)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

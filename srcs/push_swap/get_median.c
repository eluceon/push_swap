/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_median.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eluceon <eluceon@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 23:10:29 by eluceon           #+#    #+#             */
/*   Updated: 2021/04/25 10:20:55 by eluceon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_median(int *median, t_stack *stack, int len)
{
	int			*tmp_array;
	t_nbr_list	*tmp_list;
	int			i;

	tmp_list = stack->head;
	tmp_array = (int *)malloc(sizeof(int) * len);
	if (!tmp_array)
		return (0);
	i = -1;
	while (++i < len)
	{
		tmp_array[i] = tmp_list->nbr;
		tmp_list = tmp_list->next;
	}
	ft_quick_sort(tmp_array, 0, len - 1);
	*median = tmp_array[len / 2];
	free(tmp_array);
	return (1);
}

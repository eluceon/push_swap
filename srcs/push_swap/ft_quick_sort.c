/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eluceon <eluceon@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 23:04:50 by eluceon           #+#    #+#             */
/*   Updated: 2021/04/25 10:13:41 by eluceon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	partition(int *array, int start, int end)
{
	int	i;
	int	j;
	int	tmp;

	i = start - 1;
	j = start - 1;
	tmp = 0;
	while (++j < end)
	{
		if (array[j] <= array[end])
		{
			tmp = array[++i];
			array[i] = array[j];
			array[j] = tmp;
		}
	}
	tmp = array[++i];
	array[i] = array[end];
	array[end] = tmp;
	return (i);
}

void	ft_quick_sort(int *array, int start, int end)
{
	int	pivot_index;

	if (start < end)
	{
		pivot_index = partition(array, start, end);
		ft_quick_sort(array, start, pivot_index - 1);
		ft_quick_sort(array, pivot_index + 1, end);
	}
}

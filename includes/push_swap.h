/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eluceon <eluceon@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 11:18:48 by eluceon           #+#    #+#             */
/*   Updated: 2021/04/25 22:34:33 by eluceon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "common.h"

int		sort_stack_a(t_ps *ps, int len);
int		sort_stack_b(t_ps *ps, int len);
int		get_median(int *median, t_stack *stack, int len);
void	ft_quick_sort(int *array, int start, int end);
void	sort_three_or_less_numbers_a(t_ps *ps, int len);
void	sort_three_numbers_in_stack(t_ps *ps);
void	sort_two_numbers_b(t_ps *ps, int len);
void	sort_push_three_or_less_numbers_b(t_ps *ps, int len);

#endif

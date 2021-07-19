/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eluceon <eluceon@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 18:01:06 by eluceon           #+#    #+#             */
/*   Updated: 2021/04/23 18:22:24 by eluceon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int	check_options(int *options, char *arg)
{
	if (!ft_strncmp(arg, "-c", 3))
	{
		*options = FLAG_COLOR;
		return (1);
	}
	else if (!ft_strncmp(arg, "-v", 3))
	{
		*options = FLAG_STACK_STATUS;
		return (1);
	}
	else if (!ft_strncmp(arg, "-cv", 4) || !ft_strncmp(arg, "-vc", 4))
	{
		*options = FLAG_STACK_STATUS + FLAG_COLOR;
		return (1);
	}
	return (0);
}

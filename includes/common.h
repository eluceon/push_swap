/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eluceon <eluceon@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 20:12:16 by eluceon           #+#    #+#             */
/*   Updated: 2021/05/06 18:53:27 by eluceon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

# include <stdlib.h>
# include "libft.h"
# include "get_next_line.h"

# define MAX_INT "2147483647"
# define MIN_INT "-2147483648"

# define FLAG_STACK_STATUS		0b00000001
# define FLAG_COLOR				0b00000010
# define PRINT_CMD_NAME			0b00000100
# define NO_CMD_NAME			0b00000000

# define COLOR_FIRST_A			0b00000001
# define COLOR_SECOND_A			0b00000010
# define COLOR_LAST_A			0b00000100
# define COLOR_FIRST_B			0b00001000
# define COLOR_SECOND_B			0b00010000
# define COLOR_LAST_B			0b00100000

# define ASC_ORDER				1
# define DESC_ORDER				0

typedef struct s_command_list
{
	char					*command;
	struct s_command_list	*next;

}				t_command_list;

typedef struct s_nbr_list
{
	int					nbr;
	int					last;
	struct s_nbr_list	*next;
	struct s_nbr_list	*prev;
}				t_nbr_list;

typedef struct s_stack
{
	int			len;
	int			median;
	t_nbr_list	*head;
}				t_stack;

typedef struct s_push_swap
{
	int				options;
	t_command_list	*cmd_head;
	t_stack			a;
	t_stack			b;
}					t_ps;

void			exit_error(void);
void			exit_error_free(t_nbr_list 	**head);
void			exit_error_all(t_ps *ps);
void			check_integers(char **argv, int start_arg);
int				check_options(int *options, char *arg);
void			get_numbers(char **argv, t_nbr_list **head, int *a_len);
t_nbr_list		*new_nbr_list(int nbr);
void			append_nbr_list(t_nbr_list **head, t_nbr_list *new);
void			nbr_list_clear(t_nbr_list **head);
void			init_ps(t_ps *ps);
void			do_sa(t_ps *ps, int print_cmd);
void			do_sb(t_ps *ps, int print_cmd);
void			do_ss(t_ps *ps);
void			do_ra(t_ps	*ps);
void			do_rb(t_ps	*ps);
void			do_rr(t_ps	*ps);
void			do_rra(t_ps	*ps);
void			do_rrb(t_ps	*ps);
void			do_rrr(t_ps	*ps);
void			do_pa(t_ps *ps);
void			do_pb(t_ps *ps);
void			option_print(t_ps *ps, char *cmd_name, int color_element);
int				is_sorted(t_stack stack, int len, int order);
int				nbr_listsize(t_nbr_list *head);

#endif

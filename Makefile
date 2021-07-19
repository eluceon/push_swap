# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eluceon <eluceon@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/08 06:51:59 by eluceon           #+#    #+#              #
#    Updated: 2021/05/06 23:37:46 by eluceon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NONE = \033[0;0m
RED = \033[0;31m
GREEN = \033[0;32m
PURPLE = \033[0;35m

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

LIBFT = ./srcs/libft/libft.a
LIBFTDIR = ./srcs/libft/
LIBFTHEADER = libft.h
LIBFTHEADERDIR = ./srcs/libft/includes/

NAME_PUSH_SWAP = push_swap
NAME_CHECKER = checker

OBJDIR = ./obj/
HEADERDIR = ./includes/

SRCDIR_PUSH_SWAP = ./srcs/push_swap/
SRCS_PUSH_SWAP = push_swap.c get_median.c ft_quick_sort.c \
					sort_short_stacks.c sort_three_or_less_numbers.c
OBJ_PUSH_SWAP = $(addprefix $(OBJDIR), $(SRCS_PUSH_SWAP:.c=.o))
HEADER_PUSH_SWAP = $(addprefix $(HEADERDIR), push_swap.h)

SRCDIR_CHECKER = ./srcs/checker/
SRCS_CHECKER = checker.c get_commands.c
OBJ_CHECKER = $(addprefix $(OBJDIR), $(SRCS_CHECKER:.c=.o))
HEADER_CHECKER = $(addprefix $(HEADERDIR), checker.h)

SRC_COMMON_DIR = ./srcs/common/
SRCS_COMMON = exit_error.c get_numbers.c nbr_linked_list.c init_ps.c \
				swaps.c rotations_a.c rotations_b.c pushes.c \
				option_print.c is_sorted.c check_options.c
OBJ_COMMON = $(addprefix $(OBJDIR), $(SRCS_COMMON:.c=.o))
HEADER_COMMON = $(addprefix $(HEADERDIR), common.h)

SRC_GNL_DIR = ./srcs/gnl/
SRCS_GNL = get_next_line.c get_next_line_utils.c
OBJ_GNL = $(addprefix $(OBJDIR), $(SRCS_GNL:.c=.o))
HEADER_GNL = $(addprefix $(HEADERDIR), get_next_line.h)

OBJ_ALL = $(OBJ_PUSH_SWAP) $(OBJ_CHECKER) $(OBJ_COMMON) $(OBJ_GNL)

all: make_libft $(NAME_PUSH_SWAP) $(NAME_CHECKER)

bonus: all

make_libft:
	$(MAKE) -C $(LIBFTDIR)

$(NAME_PUSH_SWAP): $(OBJDIR) $(OBJ_PUSH_SWAP) $(OBJ_COMMON) $(OBJ_GNL) $(HEADER_PUSH_SWAP) $(HEADER_COMMON) $(HEADER_GNL) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ_PUSH_SWAP) $(OBJ_COMMON) $(OBJ_GNL) $(LIBFT) -o $@
	@echo "$(PURPLE) $(NAME_PUSH_SWAP) has been created $(NONE)"

$(NAME_CHECKER): $(OBJDIR) $(OBJ_CHECKER) $(OBJ_COMMON) $(OBJ_GNL) $(HEADER_CHECKER) $(HEADER_COMMON) $(HEADER_GNL) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ_CHECKER) $(OBJ_COMMON) $(OBJ_GNL) $(LIBFT) -o $@
	@echo "$(PURPLE) $(NAME_CHECKER) has been created $(NONE)"

$(OBJDIR):
	mkdir -p $(OBJDIR)

################################
##   push_swap compilation    ##
################################

$(OBJ_PUSH_SWAP): $(OBJDIR)%.o: $(SRCDIR_PUSH_SWAP)%.c $(HEADER_PUSH_SWAP) $(HEADER_COMMON) $(LIBFT)
	$(CC) $(CFLAGS) -I$(HEADERDIR) -I$(LIBFTDIR) -c $< -o $@
	@echo "$(GREEN) Object file $(PURPLE)$@ $(GREEN)for push_swap has been created $(NONE)"

###############################
##    checker compilation    ##
###############################

$(OBJ_CHECKER): $(OBJDIR)%.o: $(SRCDIR_CHECKER)%.c $(HEADER_CHECKER) $(HEADER_COMMON) $(LIBFT)
	$(CC) $(CFLAGS) -I$(HEADERDIR) -I$(LIBFTDIR) -c $< -o $@
	@echo "$(GREEN) Object file $(PURPLE)$@ $(GREEN)for checker has been created $(NONE)"

#############################
##   common compilation    ##
#############################

$(OBJ_COMMON): $(OBJDIR)%.o: $(SRC_COMMON_DIR)%.c $(HEADER_COMMON) $(LIBFT)
	$(CC) $(CFLAGS) -I$(HEADERDIR) -I$(LIBFTDIR) -c $< -o $@
	@echo "$(GREEN) Object file $(PURPLE)$@ $(GREEN) for common has been created $(NONE)"

###########################
##    GNL compilation    ##
###########################

$(OBJ_GNL): $(OBJDIR)%.o: $(SRC_GNL_DIR)%.c $(HEADER_GNL)
	$(CC) $(CFLAGS) -I$(HEADERDIR) -c $< -o $@
	@echo "$(GREEN) Object file $(PURPLE)$@$(GREEN) for gnl has been created $(B&W)"

clean:
	$(MAKE)	clean -C $(LIBFTDIR)
	$(RM) $(OBJDIR)
	@echo "$(RED) $(OBJDIR) has been deleted $(NONE)"

fclean: clean
	$(MAKE)	fclean -C $(LIBFTDIR)
	$(RM) $(NAME_PUSH_SWAP)
	@echo "$(RED) $(NAME_PUSH_SWAP) has been deleted $(NONE)"
	$(RM) $(NAME_CHECKER)
	@echo "$(RED) $(NAME_CHECKER) has been deleted $(NONE)"

re:	fclean all

.PHONY: all bonus clean fclean re

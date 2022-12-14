# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: becastro <becastro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/29 21:01:08 by becastro          #+#    #+#              #
#    Updated: 2022/12/10 13:31:49 by becastro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ../execs/philo_bonus
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g3 #$(SANITIZE)

#debug
VALGRIND = valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes
SANITIZE = -fsanitize=address -g3

#directories
EXEC_DIR	= ../execs
INC_DIR		= includes/
SRC_DIR		= srcs/
OBJ_DIR		= ../objs/
INC_FLAG	= -I $(INC_DIR)
SRC_FILES	=	args_bonus					\
				main_bonus					\
				time_bonus					\
				utils_bonus					\
				nodes_bonus					\
				simulation_routines_bonus	\
				simulation_logic_bonus		\
				simulation_init_bonus		\
				simulation_prints_bonus		\

SRC = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJS = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
.SILENT:

all: $(NAME)

$(NAME): $(OBJS)
	printf "$(B_GRN)Creating bonus executable\n$(NC)"
	mkdir -p $(EXEC_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(INC_FLAG) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	mkdir -p $(OBJ_DIR)
	printf "$(B_WHT)Creating bonus object$(NC) $(B_BLU)%s$(NC)\n" $(shell echo $@ | cut -d / -f 3 | cut -d . -f1)
	$(CC) $(CFLAGS) $(INC_FLAG) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	printf "$(B_RED)Removing$(NC)$(B_WHT) bonus binary files\n"
fclean: clean
	rm -f $(NAME)
	printf "$(B_RED)Removing$(NC) $(B_WHT)bonus executable$(NC)\n"
	rm -rf $(EXEC_DIR)
	printf "$(B_RED)Deleting$(NC) $(B_WHT)executable dir$(NC)\n"

re: fclean all


#colors
BLK	=	\e[0;30m
RED	=	\e[0;31m
GRN	=	\e[0;32m
YEL	=	\e[0;33m
BLU	=	\e[0;34m
MAG	=	\e[0;35m
CYN	=	\e[0;36m
WHT	=	\e[0;37m

B_BLK	=	\e[1;30m
B_RED	=	\e[1;31m
B_GRN	=	\e[1;32m
B_YEL	=	\e[1;33m
B_BLU	=	\e[1;34m
B_MAG	=	\e[1;35m
B_CYN	=	\e[1;36m
B_WHT	=	\e[1;37m
NC	=	\e[0m

.PHONY: all clean fclean re


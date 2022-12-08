# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: becastro <becastro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/29 21:01:08 by becastro          #+#    #+#              #
#    Updated: 2022/12/08 15:03:34 by becastro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ../$(EXEC_DIR)/philo_bonus
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror #$(SANITIZE)

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


all: $(NAME)


$(NAME): $(OBJS)
	mkdir -p $(EXEC_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(INC_FLAG) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INC_FLAG) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

sanitize:
	@$(CC) $(CFLAGS) $(SRC_DIR) $(SANITIZE) $(INC_DIR)*.c -o $(NAME)

valgrind:
	@$(VALGRIND) ./NAME

run: all
	@./$(NAME)

.PHONY: all clean fclean re valgrin run

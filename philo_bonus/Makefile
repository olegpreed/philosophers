# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: preed <preed@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/14 16:26:04 by preed             #+#    #+#              #
#    Updated: 2022/06/19 20:10:39 by preed            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus

CC       = gcc
INC      = includes
FLAGS    = -g -Wall -Wextra -Werror
HEADER   = philo_bonus.h

OBJS_DIR = objs/
SRCS_DIR = src/

SRCS     = main_bonus.c parser_bonus.c philo_bonus.c utils_bonus.c libft_bonus.c

OBJS = $(addprefix $(OBJS_DIR), $(SRCS:%.c=%.o))

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	$(CC) $(FLAGS) -c $< -o $@ -I$(INC)

all: $(NAME)

$(OBJS_DIR):
	mkdir -p $@

$(NAME): $(OBJS_DIR) $(OBJS) Makefile
	$(CC) $(FLAGS) $(OBJS) -o $(NAME) -I$(INC)

clean:
	rm -rvf $(OBJS_DIR)
	
fclean: clean
	rm -f $(NAME)

re: fclean all

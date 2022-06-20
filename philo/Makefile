# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: preed <preed@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/20 19:17:10 by preed             #+#    #+#              #
#    Updated: 2022/06/14 16:33:44 by preed            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME     = philo

CC       = gcc
INC      = includes
FLAGS    = -Wall -Wextra -Werror
HEADER   = philo.h

OBJS_DIR = objs/
SRCS_DIR = src/

SRCS     = main.c parcer.c utils.c philo.c libft.c

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


# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/13 13:40:11 by tbenedic          #+#    #+#              #
#    Updated: 2018/08/14 14:35:12 by tbenedic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ./resources/players/filler

LIB_DIR = -L./get_next_line/libft/
#LIB = $(join $(LIB_DIR), libft.a)
LIB= -lft
SRCC = $(addsuffix .c, $(FUNCS))
SRCO = $(addsuffix .o, $(FUNCS))
CC = gcc $(CFLAGS)
CFLAGS = -Wall -Werror -Wextra
FUNCS = get_next_line/get_next_line \
	   	main \
		place \
		offset \
		start_play_stop 

HEAD = filler.h
all: $(NAME)
$(LIB):
	make -s -C ./get_next_line/libft
$(NAME): $(LIB)
		gcc -Wall -Werror -Wextra $(SRCC) $(LIB_DIR) $(LIB) -o $(NAME)
run: all
	./resources/filler_vm -p1 ../resources/players/abanlin.filler -p2 $(NAME) -f ./resources/maps/map00

clean:
		rm -f $(NAME)
fclean: clean
		rm -f $(NAME) 
re: fclean all

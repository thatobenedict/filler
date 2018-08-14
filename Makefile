# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/13 13:40:11 by tbenedic          #+#    #+#              #
#    Updated: 2018/08/14 17:52:20 by tbenedic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = filler

SRCC = $(addsuffix .c, $(FUNCS))
SRCO = $(addsuffix .o, $(FUNCS_O))
FUNCS = get_next_line/get_next_line \
	   	main \
		place \
		offset \
		start_play_stop 
FUNCS_O = get_next_line \
	   	main \
		place \
		offset \
		start_play_stop 

LIBFT = get_next_line/libft/libft.a
HEAD = filler.h

all: $(NAME)

$(NAME):
	make -C get_next_line/libft
	gcc -Wall -Werror -Wextra -c $(SRCC)
	gcc -Wall -Werror -Wextra -o $(NAME) $(SRCO) $(LIBFT) 

clean: libclean
		rm -f $(SRCO)

fclean: clean libfclean
		rm -f $(NAME) 

libclean:
		@make clean -C ./get_next_line/libft/
libfclean:
		@make fclean -C ./get_next_line/libft/

re: fclean all

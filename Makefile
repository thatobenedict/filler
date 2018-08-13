# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/13 13:40:11 by tbenedic          #+#    #+#              #
#    Updated: 2018/08/13 13:54:17 by tbenedic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = filler.a

FUNCS = get_next_line/get_next_line main place offset
LIBA = get_next_line/libft/libft.a
SRCC = $(addsuffix .c, $(FUNCS))
SRCO = $(addsuffix .o, $(FUNCS))
YOU = filler

HEAD = filler.h

all: $(NAME)

$(NAME):
		gcc -Wall -Werror -Wextra -c $(SRCC) $(LIBA)
		ar rc $(NAME) $(SRCO)
		ranlib $(NAME)

clean:
		rm -f $(SRCO)

fclean: clean
		rm -f $(NAME) 

re: fclean all

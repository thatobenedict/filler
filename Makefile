# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/12 11:33:28 by tbenedic          #+#    #+#              #
#    Updated: 2018/07/16 17:40:59 by tbenedic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = tbenedic.filler

\\FUNCS = will add c files later

SRCC = $(addsuffix .c, $(FUNCS))
SRCO = $(addsuffix .o, $(FUNCS))

\\HEAD = will refer to filler later

all: $(NAME)

$(NAME):
	gcc -Wall -Werror -Wextra -c $(SRCC)
	ar rc $(NAME) $(SRCO)
	ranlib $(NAME)

clean:
	rm -f $(SRCO)

fclean: clean
	rm -f $(NAME)

re: fclean all

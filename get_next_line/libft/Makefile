# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/28 13:11:27 by tbenedic          #+#    #+#              #
#    Updated: 2018/07/22 15:24:23 by tbenedic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FUNCS = ft_atoi ft_atoi ft_bzero ft_isalnum ft_isalnum ft_isalpha \
ft_isalpha ft_isascii ft_isascii ft_isdigit ft_isdigit ft_isprint ft_isprint ft_memccpy ft_memchr ft_memcmp \
ft_memcpy ft_memmove ft_memset ft_putchar ft_putchar ft_putstr ft_putstr ft_strcat ft_strcat ft_strchr \
ft_strcmp ft_strcmp ft_strcpy ft_strcpy ft_strdup ft_strlen ft_strlen ft_strncat ft_strncmp ft_strncmp \
ft_strncpy ft_strncpy ft_strnstr ft_strrchr ft_strstr ft_strstr ft_tolower ft_tolower ft_toupper ft_toupper \
ft_memdel ft_memalloc ft_strlcat ft_whitespace ft_strnew \
ft_strdel ft_putchar_fd ft_putendl ft_putstr_fd ft_putendl_fd ft_striter ft_striteri ft_putnbr ft_putnbr_fd \
ft_strclr ft_strmap ft_strmapi ft_strequ ft_strnequ ft_strsub ft_strjoin ft_strtrim ft_strsplit ft_strsplit_word ft_itoa \
ft_strrev ft_ismin ft_ismax ft_white_word_count ft_strnjoin ft_strndup ft_contain_char ft_strjoin_2 ft_strstr_io ft_puttab \

SRCC = $(addsuffix .c, $(FUNCS))
SRCO = $(addsuffix .o, $(FUNCS)) 

HEAD = libft.h

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

norm:
	norminette libft.h
	norminette $(wordlist 1, 20, $(CFILES))
	norminette $(wordlist 21, 40, $(CFILES))
	norminette $(wordlist 41, 60, $(CFILES))
	norminette $(wordlist 61, 80, $(CFILES))
	norminette $(wordlist 81, 100, $(CFILES))

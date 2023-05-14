# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pszleper <pszleper@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/11 18:16:54 by pszleper          #+#    #+#              #
#    Updated: 2023/05/14 07:06:37 by pszleper         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COMPILATION = c++ -Wall -Wextra -Werror -std=c++98

SRC = megaphone.cpp

NAME = megaphone

all: $(NAME)

$(NAME): megaphone.o
	$(COMPILATION) $^ -o $(NAME)

megaphone.o: megaphone.cpp
	$(COMPILATION) $(SRC) -c -o $@

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
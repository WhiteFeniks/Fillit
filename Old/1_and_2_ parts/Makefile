# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: klaurine <klaurine@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/28 17:11:53 by klaurine          #+#    #+#              #
#    Updated: 2019/07/08 17:33:00 by klaurine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCE=first_part.c

NAME=fillit

FLAGS=-Wall -Wextra -Werror

OBJECTS=fillit.o
all: $(NAME)

# %.o : %.c
#      gcc -c $(FLAGS) $^ -o $@

$(NAME):
	#make -C libft/ fclean && make -C libft/
	gcc -g $(SOURCE) -o $(NAME) libft/libft.a

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

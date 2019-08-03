# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: klaurine <klaurine@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/28 17:11:53 by klaurine          #+#    #+#              #
#    Updated: 2019/07/11 15:13:21 by klaurine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = first_part.c second_part.c third_part.c main.c

OBJ = $(SRC:.c=.o)

LIBFT = includes/libft.a

HEADER = -c -I fillit.h

all: $(NAME)

$(OBJ): %.o: %.c
		@gcc -c -Wall -Werror -Wextra -I includes/ $< -o $@

$(LIBFT):
	@make -C includes

$(NAME): $(LIBFT) $(OBJ)
	@gcc $(OBJ) $(LIBFT) -o $(NAME)

clean:
	/bin/rm -f $(OBJ)
	@make -C includes clean

fclean: clean
	/bin/rm -f $(NAME)
	@make -C includes fclean

re: fclean all
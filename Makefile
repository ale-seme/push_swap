# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: asemerar <asemerar@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2023/12/08 12:38:55 by asemerar      #+#    #+#                  #
#    Updated: 2024/01/17 21:27:12 by asemerar      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

CFLAGS = -Werror -Wall -Wextra -fsanitize=address

RM = rm -rf

SRCS = 	src/main.c src/manage_index.c src/initial_sort.c src/mov_pushes.c src/mov_rev_rotate.c src/mov_swap.c \
		 src/mov_rotate.c src/sorting_algorithm.c src/utilities_for_sorting.c libft/libft.a


$(NAME) : 
	make bonus -C libft
	cc $(CFLAGS) $(SRCS) -o $(NAME)

all : $(NAME)

fclean : clean
	$(RM) $(NAME)
	make fclean -C libft

clean :
	$(RM) $(NAME)
	make clean -C libft

re : fclean all
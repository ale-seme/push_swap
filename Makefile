# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: asemerar <asemerar@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2023/12/08 12:38:55 by asemerar      #+#    #+#                  #
#    Updated: 2024/01/15 17:11:19 by asemerar      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Werror -Wextra -fsanitize=address

SRCS =	main.c manage_index.c initial_sort.c mov_pushes.c mov_rev_rotate.c mov_swap.c \
		 move_rotate.c sorting_algorithm.c utilities_for_sorting.c \
		 libft/libft.a
		 
OBJS = $(SRCS:.c=.o)

NAME = push_swap
# Targets
all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
NAME = push_swap

CC = cc

CFLAGS = -Werror -Wall -Wextra -fsanitize=address

RM = rm -rf

SRCS = src/main.c src/manage_index.c src/initial_sort.c src/mov_pushes.c \
       src/mov_rev_rotate.c src/mov_swap.c src/mov_rotate.c \
       src/sorting_algorithm.c src/utilities_for_sorting.c src/utilities_for_main.c

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

OBJS = $(SRCS:.c=.o)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L$(LIBFT_DIR) -lft

$(LIBFT):
	make bonus -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

fclean: clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT_DIR)

clean:
	$(RM) $(OBJS)
	make clean -C $(LIBFT_DIR)

re: fclean all

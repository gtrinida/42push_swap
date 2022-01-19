NAME = push_swap.a
CC = gcc
INCLUDES = push_swap.h
CFLAGS = -Wall -Wextra -Werror

SRCS = push_swap.c

OBJS = $(SRCS:%.c=%.o)

%.o: %.c $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -libft

$(NAME): $(OBJS)
	@make -C libft
	$(CC) -o $(NAME) $(OBJS) $(CFLAGS) libft/libft.a

all: $(NAME)

clean:
	@make -C libft fclean
	$(RM) $(OBJS)

fclean: clean
	@make -C libft fclean
	$(RM) $(NAME)

re: clean all
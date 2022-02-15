NAME = push_swap.a
CC = gcc
INCLUDES = push_swap.h
CFLAGS = -Wall -Wextra -Werror

SRCS = push_swap.c\
	analysis.c\
	c_first.c\
	c_second.c\ 
	c_third.c\
	c_utils.c\
	sort_3.c\
	sort_4_5.c\ 
	sort_large.c\ 
	sort_large_second.c\ 
	sort_large_utils.c\
	verification.c\
	verification_utils.c\
	atoi_overflow.c

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
CC = gcc
INC = .
INCLUDES = push_swap.h
CFLAGS = -g -Wall -Wextra -Werror

NAME = push_swap
SRCS = push_swap.c \
	analysis.c \
	c_first.c \
	c_second.c \
	c_third.c \
	c_utils.c \
	sort_3_elem.c \
	sort_4_5_elem.c \
	sort_large.c \
	sort_large_second.c \
	sort_large_utils.c \
	verification.c \
	verification_utils.c \
	atoi_overflow.c \
	verification_second.c 

OBJS = $(SRCS:%.c=%.o)

%.o: %.c $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -Ilibft

$(NAME): $(OBJS)
	@make -C libft
	$(CC) -o $(NAME) $(OBJS) $(CFLAGS) -I$(INC) libft/libft.a

all: $(NAME)

clean:
	@make -C libft clean
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	@make -C libft fclean
	$(RM) $(NAME) $(NAME_BONUS)

re: clean all

norme:
	norminette libft/*.c libft/*.h

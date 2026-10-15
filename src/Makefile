NAME = printf.a

SRCS = ft_printf.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

LIBFT = ./libft/libft.a

%.o: %.c
	cc $(CFLAGS) -c $< -o $@

all: $(NAME)

run: all
	cc $(CFLAGS) -g $(SRCS) -I. -I ./libft $(NAME) $(LIBFT) -o test_run
	./test_run

$(NAME): $(OBJS) $(LIBFT)
	ar rcs $(NAME) $(OBJS)

$(LIBFT):
	$(MAKE) -C ./libft

clean:
	rm -f $(OBJS)
	rm -f test_run
	$(MAKE) -C ./libft fclean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re


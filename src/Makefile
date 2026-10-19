NAME = libftprintf.a

SRCS = ft_printf.c handle_p.c handle_nums.c handle_chrs.c handle_hex.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

LIBFT = ./libft/libft.a

%.o: %.c
	cc $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJS)

$(LIBFT):
	$(MAKE) -C ./libft

clean:
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C ./libft fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

NAME = libftprintf.a

SRCS = ft_printf.c handle_chrs.c handle_hex.c handle_num.c handle_p.c handle_u_num.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

%.o: %.c
	cc $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

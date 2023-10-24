NAME   =	libftprintf.a
SRCS   = 	ft_libft.c        \
			ft_printf_utils.c \
			ft_printf.c       \
			ft_put_hex.c      \
			ft_put_ptr.c      \
			ft_put_uint.c

OBJS   = $(SRCS:.c=.o)

CC     = cc
CFLAGS = -Wall -Wextra -Werror

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all .c.o clean fclean re
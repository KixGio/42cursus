NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Werror -Wextra

RM = rm -f

SRC = ft_print_char.c ft_print_hex.c ft_print_int.c ft_print_nbr_base.c \
	ft_print_ptr.c ft_print_str.c ft_printf.c ft_strlen.c

OBJS = ${SRC:.c=.o}

$(NAME): $(OBJS)
		ar rcs ${NAME} ${OBJS}

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
		$(RM) $(OBJS)

fclean:	clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

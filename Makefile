NAME= libftprintf.a
CC=cc
CFLAGS= -Wall -Wextra -Werror
SRC= src/ft_printf.c src/ft_printf_u.c src/ft_printf_u2.c
OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re : fclean all

.PHONY: clean
.SECONDARY: $(OBJS)
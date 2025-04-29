NAME = libftprintf.a
SRCS = ft_printf.c ft_string.c ft_digit.c
OBJS = $(SRCS:.c=.o)
AR = ar rcs
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCS = .
DEL = rm -f

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I $(INCS)

$(NAME): $(OBJS)
		$(AR) $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
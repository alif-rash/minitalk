NAME_S = server

NAME_C = client

CC = cc

SRCS_S = server.c
SRCS_C = client.c

OBJS_S = $(SRCS_S:.c=.o)
OBJS_C = $(SRCS_C:.c=.o)

CFLAGS = -Wall -Wextra -Werror

PRINTF_DIR = ft_printf
PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a 
PRINTF_INC = -I$(PRINTF_DIR)

$(NAME_S): $(OBJS_S) $(PRINTF_LIB)
	$(CC) $(CFLAGS) -o $(NAME_S) $(OBJS_S) $(PRINTF_INC) $(PRINTF_LIB)

$(NAME_C): $(OBJS_C) $(PRINTF_LIB)
	$(CC) $(CFLAGS) -o $(NAME_C) $(OBJS_C) $(PRINTF_INC) $(PRINTF_LIB)

$(PRINTF_LIB):
	make -C $(PRINTF_DIR)

all: $(NAME_S) $(NAME_C)

clean:
	$(RM) $(OBJS_S) $(OBJS_C)
	make -C $(PRINTF_DIR) clean

fclean: clean
	$(RM) $(NAME_S) $(NAME_C)
	make -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
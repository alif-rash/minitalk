NAME_S = server
NAME_C = client
NAME_S_BONUS = server_bonus
NAME_C_BONUS = client_bonus

CC = cc

SRCS_S = server.c
SRCS_C = client.c
SRCS_S_BONUS = server_bonus.c
SRCS_C_BONUS = client_bonus.c

OBJS_S = $(SRCS_S:.c=.o)
OBJS_C = $(SRCS_C:.c=.o)
OBJS_S_BONUS = $(SRCS_S_BONUS:.c=.o)
OBJS_C_BONUS = $(SRCS_C_BONUS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

PRINTF_DIR = ft_printf
PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a 
PRINTF_INC = -I$(PRINTF_DIR)

all: $(NAME_S) $(NAME_C)

$(NAME_S): $(OBJS_S) $(PRINTF_LIB)
	$(CC) $(CFLAGS) -o $(NAME_S) $(OBJS_S) $(PRINTF_INC) $(PRINTF_LIB)

$(NAME_C): $(OBJS_C) $(PRINTF_LIB)
	$(CC) $(CFLAGS) -o $(NAME_C) $(OBJS_C) $(PRINTF_INC) $(PRINTF_LIB)

$(NAME_S_BONUS): $(OBJS_S_BONUS) $(PRINTF_LIB)
	$(CC) $(CFLAGS) -o $(NAME_S_BONUS) $(OBJS_S_BONUS) $(PRINTF_INC) $(PRINTF_LIB)

$(NAME_C_BONUS): $(OBJS_C_BONUS) $(PRINTF_LIB)
	$(CC) $(CFLAGS) -o $(NAME_C_BONUS) $(OBJS_C_BONUS) $(PRINTF_INC) $(PRINTF_LIB)

$(PRINTF_LIB):
	make -C $(PRINTF_DIR)

bonus: $(NAME_S_BONUS) $(NAME_C_BONUS)

clean:
	$(RM) $(OBJS_S) $(OBJS_C)
	make -C $(PRINTF_DIR) clean

fclean: clean
	$(RM) $(NAME_S) $(NAME_C)
	make -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus
NAME = pipex
NAME_BONUS = pipex_bonus

LIBFT_DIR = includes/libft
LIBFT = $(LIBFT_DIR)/libft.a

CFLAGS = -Wall -Wextra -Werror 
CC = cc

LDFLAGS = -L$(LIBFT_DIR) -lft
INC = -I$(LIBFT_DIR)

INCLUDE = pipex.h
INCLUDE_B = bonus/pipex_bonus.h
INCLUDE_GET_NEXT_LINE = bonus/get_next_line_bonus.h

SRC = pipex_utils.c \
      pipex.c

SRC_B = bonus/executing_cmd_bonus.c \
        bonus/get_next_line_bonus.c \
        bonus/get_next_line_utils_bonus.c \
        bonus/here_doc_bonus.c \
        bonus/pipex_bonus.c

OBJ = $(SRC:.c=.o)
OBJ_B = $(SRC_B:.c=.o)

all: $(NAME)

$(LIBFT): 
	$(MAKE) -C $(LIBFT_DIR)

bonus: $(NAME_BONUS)

$(OBJ): $(INCLUDE)
$(OBJ_B): $(INCLUDE_B) $(INCLUDE_GET_NEXT_LINE)

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(OBJ) $(LDFLAGS) -o $(NAME)

$(NAME_BONUS): $(OBJ_B) $(LIBFT)
	$(CC) $(OBJ_B) $(LDFLAGS) -o $(NAME_BONUS)

clean:
	@make clean -C $(LIBFT_DIR)
	@rm -f $(OBJ) $(OBJ_B)

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	@rm -f $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all bonus clean fclean re $(LIBFT)

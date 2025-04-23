C = cc

CFLAGS = -Werror -Wextra -Wall -MMD -g3 -fPIC

INCLUDES = -Iincludes -I./lib/ft_printf/includes -I./lib/libft/includes -I./lib/get_next_line/includes

LIBPRINTF = lib/ft_printf/lib/libprintf.a

LIBFT = lib/libft/lib/libft.a

GNL = lib/get_next_line/lib/getnextline.a

SRC_DIR = src
SRC_DIR_BONUS = src_bonus


OBJ_DIR = objs
OBJ_DIR_BONUS = objs_bonus

SRCS = $(shell find $(SRC_DIR) -name '*.c')
SRCS_BONUS = $(shell find $(SRC_DIR_BONUS) -name '*.c')

OBJS = $(addprefix $(OBJ_DIR)/,$(addsuffix .o,$(notdir $(basename $(SRCS)))))
OBJS_BONUS = $(addprefix $(OBJ_DIR_BONUS)/,$(addsuffix .o,$(notdir $(basename $(SRCS_BONUS)))))

DEPENDS = $(OBJS:.o=.d)

NAME = pipex
NAME_BONUS = pipex_bonus

-include $(DEPEND)

.PHONY: all
all: $(NAME) 

.PHONY: bonus
bonus: $(NAME_BONUS)

$(NAME): $(OBJS) $(LIBPRINTF) $(LIBFT)
			$(CC) $^ -o $@

$(NAME_BONUS): $(OBJS_BONUS) $(LIBPRINTF) $(LIBFT) $(GNL)
			$(CC) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR_BONUS)/%.o: $(SRC_DIR_BONUS)/%.c | $(OBJ_DIR_BONUS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR_BONUS):
	mkdir -p $(OBJ_DIR_BONUS)

$(LIBPRINTF):
	$(MAKE) -C lib/ft_printf

$(LIBFT):
	$(MAKE) -C lib/libft

$(GNL):
	$(MAKE) -C lib/get_next_line

.PHONY: clean
clean:
	rm -rf $(OBJ_DIR)
	rm -rf $(OBJ_DIR_BONUS)
	$(MAKE) -C lib/ft_printf clean
	$(MAKE) -C lib/libft clean
	$(MAKE) -C lib/get_next_line clean

.PHONY: fclean
fclean: clean
	rm -rf $(NAME)
	rm -rf $(NAME_BONUS)
	$(MAKE) -C lib/ft_printf fclean
	$(MAKE) -C lib/libft fclean
	$(MAKE) -C lib/get_next_line fclean

.PHONY: re
re: fclean all bonus

.PHONY: all clean fclean re

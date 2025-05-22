# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgoras < lgoras@student.42.fr >            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/21 14:57:30 by lgoras            #+#    #+#              #
#    Updated: 2025/05/22 19:25:47 by lgoras           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc -g
CFLAGS = -Wall -Wextra -Werror
NAME = so_long

LIBFT_DIR = BIG_LIBFT
LIBFT = $(LIBFT_DIR)/lib/libbiglibft.a
LIBFT_STAMP = $(LIBFT_DIR)/.libft_compiled
INCLUDE_LIBFT = $(LIBFT_DIR)/includes
INCLUDE = include
PATH_SRCS = srcs
PATH_PARSING = $(PATH_SRCS)/parsing
PATH_TEXTURES = $(PATH_SRCS)/textures
PATH_UTILS = $(PATH_SRCS)/utils
HEADER = $(INCLUDE)/so_long.h

SRCS = \
	$(PATH_SRCS)/main.c \
	$(PATH_UTILS)/utils.c \
	$(PATH_PARSING)/flood_fill.c \
	$(PATH_PARSING)/parsing_map.c

OBJS = $(SRCS:.c=.o)

DEF_COLOR = \033[0;39m
GRAY = \033[1;90m
RED = \033[1;91m
GREEN = \033[1;92m
YELLOW = \033[1;93m
BLUE = \033[1;94m
MAGENTA = \033[1;95m
CYAN = \033[1;96m
WHITE = \033[1;97m

all: $(NAME)

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -I$(INCLUDE) -I$(INCLUDE_LIBFT) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT_STAMP)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) \
		-I$(INCLUDE) -I$(INCLUDE_LIBFT) \
		-L$(LIBFT_DIR)/lib -lbiglibft \
		-lX11 -lXext -lm
	@echo "\033[1m$(MAGENTA)✅ SO_LONG COMPILATION DONE$(DEF_COLOR)"
	@$(MAKE) --no-print-directory loading_bar

$(LIBFT_STAMP):
	@make -C $(LIBFT_DIR) --no-print-directory
	@touch $(LIBFT_STAMP)
	@echo "\033[1m$(GREEN)✅ LIBFT & MLX COMPILATION DONE$(DEF_COLOR)"

clean:
	@rm -rf $(OBJS)
	@make -C $(LIBFT_DIR) clean --no-print-directory
	@echo "\033[1m$(YELLOW)🧹 Cleaned object files$(DEF_COLOR)"

fclean: clean
	@rm -rf $(NAME) $(LIBFT_STAMP)
	@make -C $(LIBFT_DIR) fclean --no-print-directory
	@echo "\033[1m$(RED)🧨 Removed $(NAME) & $(LIBFT_DIR) & MLX$(DEF_COLOR)"

re: fclean all

loading_bar:
	@i=0; \
	spin='⠋⠙⠹⠸⠼⠴⠦⠧⠇⠏'; \
	len=$$(expr length "$$spin"); \
	while [ $$i -le 20 ]; do \
		pos=$$(( (i % len) + 1 )); \
		char=$$(expr substr "$$spin" $$pos 1); \
		bar="$$(printf '%0.s▓' $$(seq 1 $$i))"; \
		printf "\r\033[1;96m[%-20s] %3d%% %s\033[0m" "$$bar" $$(( $$i * 5 )) "$$char"; \
		sleep 0.05; \
		i=$$((i+1)); \
	done; \
	printf "\r$(CYAN)✅ COMPILATION DONE$(DEF_COLOR)%-20s\n" "" 

.PHONY: all clean fclean re loading_bar
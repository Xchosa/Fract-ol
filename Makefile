# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/04 10:50:48 by poverbec          #+#    #+#              #
#    Updated: 2025/02/18 13:39:51 by poverbec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# NAME = fractol

# SRCS = main.c

# OBJECTS = $(SRCS).c=%.o)

# MLX 		=	$(MLX_DIR)/build/libmlx42.a -ldl -lglfw -pthread -lm -Ofast -ffast-math -march=native -mtune=native -funroll-loops

# CC = cc

# CFLAGS			= -Wall -Werror -Wextra -Wunreachable-code -Ofast -ffast-math -march=native -mtune=native -funroll-loops #-lm
# all: mlx ${NAME}

# ${NAME}: $(OBJECTS)
# 	${CC} ${CFLAGS} -o ${NAME} $(OBJECTS) $(LIBFT) $(MLX)



NAME 	= fractol
CC		= cc
CFLAGS	= -Wall -Wextra -Werror -g
LIBFT	= ./libft/libft.a
SOURCE_DIR = ./src/
MLX 		=	$(MLX_DIR)/build/libmlx42.a -ldl -lglfw -pthread -lm -Ofast -ffast-math -march=native -mtune=native -funroll-loops
MLX_DIR = ./mlx
MLX_REPO = https://github.com/codam-coding-college/MLX42.git

# ---------- Subjects ---------- #
MY_SOURCES = \
			$(SOURCE_DIR)main.c
# $(SOURCE_DIR)helper.c
			
# MY_SOURCES_BONUS = \
# 			$(SOURCE_DIR)main_bonus.c \
# 			$(SOURCE_DIR)helper_bonus.c

# ---------- Objects ---------- #
MY_OBJECTS=$(MY_SOURCES:.c=.o)
# MY_OBJECTS_BONUS=$(MY_SOURCES_BONUS:.c=.o)

# ---------- COLORS AND STUFF ---------- #
Color_Off = \033[0m
BIYellow = \033[1;93m
Yellow = \033[0;33m
BGreen = \033[1;32m 
On_Yellow = \033[43m
On_Green = \033[42m
Red = \033[0;31m

all: $(NAME)

$(NAME): $(MY_OBJECTS) $(LIBFT)
	@echo "$(BIYellow) Compiling $(NAME) $(Color_Off)"
	@$(CC) $(CFLAGS) $(MY_OBJECTS) $(LIBFT) -o $(NAME) $(MLX)
	@if [ -f $(NAME) ]; then \
		echo "$(On_Yellow)------------------------------------------$(Color_Off)"; \
		echo "$(BGreen)PROCESS COMPLETED SUCCESSFULLY!$(Color_Off)"; \
		echo "$(On_Green)------------------------------------------$(Color_Off)"; \
	else \
		echo "$(Red)failed to compile $(NAME) $(Color_Off)"; \
		exit 1; \
	fi

mlx:
	if [ ! -d "$(MLX_DIR)" ]; then git clone $(MLX_REPO) $(MLX_DIR); fi
	cmake ./mlx/ -B $(MLX_DIR)/build && make -C $(MLX_DIR)/build -j4 CFLAGS+="-Ofast -ffast-math -march=native -mtune=native -funroll-loops"

# bonus: $(MY_OBJECTS_BONUS) $(LIBFT)
# 	@echo "$(BIYellow) Compiling  Bonus $(Color_Off)"
# 	@$(CC) $(CFLAGS) $(MY_OBJECTS_BONUS) $(LIBFT) -o $(NAME)
# 	@if [ -f $(NAME) ]; then \
# 		echo "$(On_Yellow)------------------------------------------$(Color_Off)"; \
# 		echo "$(BGreen)PROCESS COMPLETED SUCCESSFULLY!$(Color_Off)"; \
# 		echo "$(On_Green)------------------------------------------$(Color_Off)"; \
# 	else \
# 		echo "$(Red)failed to compile $(NAME) $(Color_Off)"; \
# 		exit 1; \
# 	fi
	
$(LIBFT):
	make -C ./libft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(Yellow)-----Removing Object Files--------$(Color_Off)"
	@rm -f $(MY_OBJECTS)

fclean: clean
	@echo "$(On_Yellow)Removing Executables...$(Color_Off)"
	@rm -f $(NAME)
	make -C libft fclean

re: fclean all

f: fclean
f: CFLAGS += -g -fsanitize=address
f: $(NAME)

.PHONY: re clean fclean all

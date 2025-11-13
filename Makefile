# **************************************************************************** #
#                                  CONFIGURATION                               #
# **************************************************************************** #
NAME        = cub3d
CC          = gcc
# Add GL_SILENCE_DEPRECATION to suppress OpenGL deprecation warnings on macOS
CFLAGS		= -Wall -Wextra -Werror -Iincludes

SRC_DIR     = src
OBJ_DIR     = src/obj
LIBFT_DIR   = libft
MLX_DIR     = minilibx_opengl

LIBFT       = $(LIBFT_DIR)/libft.a
MLX         = $(MLX_DIR)/libmlx.a

# **************************************************************************** #
#                              MACOS LINKING FLAGS                             #
# **************************************************************************** #
# The macOS native MLX uses the AppKit and OpenGL frameworks instead of X11 libraries.
LDFLAGS_OSX = -framework OpenGL -framework AppKit

# **************************************************************************** #
#                                SOURCE FILES                                  #
# **************************************************************************** #

SRCS        = $(wildcard $(SRC_DIR)/*.c)
OBJS        = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# **************************************************************************** #
#                                   RULES                                      #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(OBJ_DIR) $(LIBFT) $(MLX) $(OBJS)
	# Corrected linking command for macOS
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) $(LDFLAGS_OSX) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -I$(MLX_DIR) -I$(SRC_DIR) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	$(MAKE) -C $(MLX_DIR)

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(MLX_DIR)
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
_mkfile_path := $(abspath $(lastword $(MAKEFILE_LIST)))
I := $(patsubst %/,%,$(dir $(_mkfile_path)))

ifneq ($(words $(MAKECMDGOALS)),1)
.DEFAULT_GOAL = all
%:
	@$(MAKE) $@ --no-print-directory -rRf $(firstword $(MAKEFILE_LIST))
else
ifndef ECHO
T := $(shell $(MAKE) $(MAKECMDGOALS) --no-print-directory \
      -nrRf $(firstword $(MAKEFILE_LIST)) \
      ECHO="COUNTTHIS" | grep -c "COUNTTHIS")
N := x
C = $(words $N)$(eval N := x $N)
ECHO = python $(I)/echo_progress.py --stepno=$C --nsteps=$T
endif

# COLORS
NOC         = \033[0m
BOLD        = \033[1m
UNDERLINE   = \033[4m
BLACK       = \033[1;30m
RED         = \033[1;31m
GREEN       = \033[1;32m
YELLOW      = \033[1;33m
BLUE        = \033[1;34m
VIOLET      = \033[1;35m
CYAN        = \033[1;36m
WHITE       = \033[1;37m

# SYMBOLS
INFO = $(WHITE)[$(BLUE)ℹ️$(WHITE)] $(NOC)
SUCCESS = $(WHITE)[$(GREEN)✅$(WHITE)] $(GREEN)
WARNING = $(WHITE)[$(YELLOW)⚠️$(WHITE)] $(YELLOW)
ERROR = $(WHITE)[$(RED)❌$(WHITE)] $(RED)

# Binary
NAME=libg.a

# Path
SRC_PATH = ./srcs/
OBJ_PATH = ./objs/
INCDIR = ./includes/

# Name
SRC_NAME = glib.c \
			vectors/vector2f.c \
			vectors/vector3f.c \
			graphics/draw.c \
			maths/rotations.c \
			maths/projections.c \
			utils/math_utils.c \
			utils/color.c

OBJ_NAME = $(SRC_NAME:.c=.o)

# Files
SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

# MinilibX
MLX		= ./mlx/
MLX_LIB	= $(addprefix $(MLX),libmlx.a)
MLX_INC	= -I ./mlx
MLX_LNK	= -L ./mlx -l mlx -I /usr/X11/include -framework OpenGL -framework AppKit

# Flags
CC = gcc $(CFLAGS)
CFLAGS = -Wall -Wextra -Werror -Imlx 

all: obj $(MLX_LIB) $(NAME)

obj:
	@echo "$(GREEN) ██████   $(RED) ██      ██ ██████$(NOC)"
	@echo "$(GREEN)██        $(RED) ██      ██ ██   ██$(NOC)"
	@echo "$(GREEN)██   ███  $(RED) ██      ██ ██████  $(NOC)"
	@echo "$(GREEN)██    ██  $(RED) ██      ██ ██   ██$(NOC)"
	@echo "$(GREEN) ██████   $(RED) ███████ ██ ██████  $(NOC)"
	@echo " "
	@echo "✅ Developed by Roch Blondiaux."
	@echo " "
	@mkdir -p $(OBJ_PATH)
	@mkdir -p $(OBJ_PATH)/graphics
	@mkdir -p $(OBJ_PATH)/maths
	@mkdir -p $(OBJ_PATH)/vectors
	@mkdir -p $(OBJ_PATH)/utils

$(OBJ_PATH)%.o:$(SRC_PATH)%.c
	@$(CC) $(CFLAGS) $(MLX_INC) -I $(INCDIR) -o $@ -c $<
	@$(ECHO) Compiling $@
	@sleep 0.01
	@touch $@

$(MLX_LIB):
	@make -C $(MLX)

$(NAME): $(OBJ)
	@ar rcs ${NAME} ${OBJ}

clean:
	@rm -rf $(OBJ_PATH)

fclean:clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean obj all $(MLX_LIB) $(NAME) fclean

endif
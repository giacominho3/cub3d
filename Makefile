NAME	= cub3D

ERROR = src/error/error_1.c

GNL = src/gnl/get_next_line.c src/gnl/get_next_line_utils.c

PARSER = src/parser/readfile.c src/parser/readfile_utils.c src/parser/check_border.c

PG = src/pg/pg.c src/pg/pg_1.c

DRAW = src/draw/draw.c src/draw/draw_1.c src/draw/get_colors.c

HOOK = src/hook/key_hook.c

RAYCAST = src/raycasting/dda.c src/raycasting/raycasting.c src/raycasting/init_utils.c

MINIMAP = src/minimap/minimap.c

UTILS = src/utils/utils.c

SRC		= main.c $(ERROR) $(GNL) $(PARSER) $(PG) \
			$(DRAW) $(RAYCAST) $(UTILS) $(HOOK) \
			$(MINIMAP)

#ANSII COLOR

RED		= \033[0;31m
BLACK	= \033[1;30m
WHITE	= \033[1;37m
BLUE	= \033[1;34m
YELLOW2  = \033[93;226m
GREEN2   = \033[92;118m
GREEN   = \e[92;5;118m
YELLOW  = \e[93;5;226m
GRAY    = \e[33;2;37m
RESET   = \e[0m
CURSIVE = \e[33;3m

CC = gcc 
FLAG = -Werror -Wextra - Wall -g

OBJS = $(SRC:.c=.o)

LIBFT = include/libft/

# UNAME := $(shell uname)

# Definizione delle librerie in base al sistema operativo
# ifeq ($(UNAME), Linux)
# 	LIBRARY = mlx_linux/
# 	LIBS = $(LIBFT)libft.a -L$(LIBRARY) -lmlx_Linux -L/usr/lib -lm -lz -lXext -lX11
# 	CCFLAGS = -I/usr/include -I$(LIBRARY) -Iminilibx
# else ifeq ($(UNAME), Darwin)
# 	LIBRARY = minilibx/
# 	LIBS = $(LIBFT)libft.a -L$(LIBRARY) -lmlx -framework OpenGL -framework AppKit
# 	CCFLAGS = -I$(LIBRARY)
# endif

LIBRARY = minilibx/
LIBS = $(LIBFT)libft.a -L$(LIBRARY) -lmlx -framework OpenGL -framework AppKit $(LIBRARY)libmlx.a
CCFLAGS = -I$(LIBRARY)
# LIBS = $(LIBFT)libft.a -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

RM = rm -f

CC = gcc -Wall -Wextra -Werror -g

.c.o:
	@${CC} $(CCFLAGS) -c $< -o ${<:.c=.o} > /dev/null

$(NAME): ${OBJS}
	@printf "$(CURSIVE)$(YELLOW) 	- Compiling libft ... $(RESET)\n"
	@make -s -C $(LIBFT)
	@printf "\e[0m\e[92m - libft compiled.$(RESET)\n"
	@printf "$(CURSIVE)$(YELLOW) 	- Compiling minilibx ... $(RESET)\n"
	@make -s -C $(LIBRARY) > /dev/null
	@printf "\e[0m\e[92m - minilibx compiled.$(RESET)\n"
	@printf "$(CURSIVE)$(YELLOW) 	- Compiling Cub3D ... $(RESET)\n"
	@$(CC) $(OBJS) $(LIBS) -o $(NAME)
	@printf "\e[0m\e[92m - Cub3D compiled.$(RESET)\n"
#	@echo "$(RED)	       		         █████╗ ██████╗ ███████╗██╗  ██╗                       "
#	@echo "$(RED)				██╔══██╗██╔══██╗██╔════╝╚██╗██╔╝                       "
#	@echo "$(RED)				███████║██████╔╝█████╗   ╚███╔╝                        "
#	@echo "$(RED)				██╔══██║██╔═══╝ ██╔══╝   ██╔██╗                        "
#	@echo "$(RED)				██║  ██║██║     ███████╗██╔╝ ██╗                       "
#	@echo "$(RED)				╚═╝  ╚═╝╚═╝     ╚══════╝╚═╝  ╚═╝                       "
#	@echo "																			"
#	@echo "$(RED)	██╗     ███████╗ ██████╗ ███████╗███╗   ██╗██████╗ ███████╗██████╗ ██████╗ "
#	@echo "$(RED)	██║     ██╔════╝██╔════╝ ██╔════╝████╗  ██║██╔══██╗██╔════╝╚════██╗██╔══██╗"
#	@echo "$(RED)	██║     █████╗  ██║  ███╗█████╗  ██╔██╗ ██║██║  ██║███████╗ █████╔╝██║  ██║"
#	@echo "$(RED)	██║     ██╔══╝  ██║   ██║██╔══╝  ██║╚██╗██║██║  ██║╚════██║ ╚═══██╗██║  ██║"
#	@echo "$(RED)	███████╗███████╗╚██████╔╝███████╗██║ ╚████║██████╔╝███████║██████╔╝██████╔╝"
#	@echo "$(RED)	╚══════╝╚══════╝ ╚═════╝ ╚══════╝╚═╝  ╚═══╝╚═════╝ ╚══════╝╚═════╝ ╚═════╝ "
#	@echo ""

all: $(NAME)

clean:
	@make -s clean -C $(LIBFT)
	@printf "\e[0m\e[92m$(RED) - OBJS libft removed.$(RESET)\n"
	@${RM} $(OBJS)
	@printf "\e[0m\e[92m$(RED) - OBJS Cub3D removed.$(RESET)\n"

fclean: clean
	@make -s fclean -C $(LIBFT)
	@printf "\e[0m\e[92m$(RED) - library libft removed.$(RESET)\n"
	@make -s clean -C $(LIBRARY) > /dev/null
	@printf "\e[0m\e[92m$(RED) - library minilibx removed.$(RESET)\n"
	@${RM} $(NAME) ${OBJB}
	@printf "\e[0m\e[92m$(RED) - Cub3D removed.$(RESET)\n"

re: fclean all

.PHONY: all clean fclean re
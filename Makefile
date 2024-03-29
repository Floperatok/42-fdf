####################################################################
#                            CONFIG                                #
####################################################################

CC				=	cc
CFLAGS			=	-Wall -Werror -Wextra
NAME			=	fdf

####################################################################
#                            FILES                                 #
####################################################################

SRC				=	main.c \
					exit.c \
					draw.c \
					init.c \
					map.c \
					render.c \
					utils.c \
					rotation.c \
					computation.c \
					color.c \
					user_input.c

LIBFT			=	libft.a

MLX				=	libmlx.a

OBJ				=	$(SRC:.c=.o)

####################################################################
#                            PATHS                                 #
####################################################################

OBJ_PATH		=	src/obj/
SRC_PATH		=	src/
LIBFT_PATH		=	libs/libft/
MLX_PATH		=	libs/minilibx-linux/

SRCS			=	$(addprefix $(SRC_PATH), $(SRC))
OBJS			=	$(addprefix $(OBJ_PATH), $(OBJ))
LIBFTS			=	$(addprefix $(LIBFT_PATH), $(LIBFT))
MLXS			=	$(addprefix $(MLX_PATH), $(MLX))

INCS			=	./include/


####################################################################
#                            RULES                                 #
####################################################################

all:	$(NAME)

$(NAME):	$(OBJS)
	@echo -n "$(COM_COLOR)compiling libft...     $(NO_COLOR)"
	@make -sC $(LIBFT_PATH)
	@echo "$(COM_COLOR)done: $(OK_COLOR)[✓]$(NO_COLOR)"

	@echo -n "$(COM_COLOR)compiling mlx...       $(NO_COLOR)"
	@echo "$(COM_COLOR)done: $(OK_COLOR)[✓]$(NO_COLOR)"
	@make -s -C $(MLX_PATH)

	@echo -n "$(COM_COLOR)compiling $(NAME)...       $(NO_COLOR)"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFTS) $(MLXS) -lX11 -lXext \
		-o $(NAME) -I $(INCS) -lm
	@echo "$(COM_COLOR)done: $(OK_COLOR)[✓]$(NO_COLOR)"

$(OBJ_PATH)%.o:	$(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(INCS)

clean:
	@rm -rf $(OBJ_PATH)
	@echo "$(COM_COLOR)clean:                       $(OK_COLOR)[✓]$(NO_COLOR)"
	@make -sC $(LIBFT_PATH) clean
	@make -sC $(MLX_PATH) clean
	@echo "$(COM_COLOR)clean mlx:                   $(OK_COLOR)[✓]$(NO_COLOR)"

fclean:
	@rm -rf $(OBJ_PATH)
	@rm -f $(NAME)
	@echo "$(COM_COLOR)fclean:                      $(OK_COLOR)[✓]$(NO_COLOR)"
	@make -sC $(LIBFT_PATH) fclean
	@make -sC $(MLX_PATH) clean
	@echo "$(COM_COLOR)clean mlx:                   $(OK_COLOR)[✓]$(NO_COLOR)"

re: fclean all

####################################################################
#                            COLORS                                #
####################################################################

COM_COLOR   = \033[0;34m
OK_COLOR    = \033[0;32m
NO_COLOR    = \033[m
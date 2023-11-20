####################################################################
#                            CONFIG                                #
####################################################################

CC				=	cc
CFLAGS			=	-Wall -Werror -Wextra -g
NAME			=	fdf

####################################################################
#                            FILES                                 #
####################################################################

SRC				=	main.c

FT_PRINTF		=	ft_printf.a

MLX				=	libmlx.a

OBJ				=	$(SRC:.c=.o)

####################################################################
#                            PATHS                                 #
####################################################################

OBJ_PATH		=	src/obj/
SRC_PATH		=	src/
FT_PRINTF_PATH	=	libs/ft_printf/
MLX_PATH		=	libs/minilibx-linux/

SRCS			=	$(addprefix $(SRC_PATH), $(SRC))
OBJS			=	$(addprefix $(OBJ_PATH), $(OBJ))
FT_PRINTFS		=	$(addprefix $(FT_PRINTF_PATH), $(FT_PRINTF))
MLXS			=	$(addprefix $(MLX_PATH), $(MLX))

INCS			=	./include/


####################################################################
#                            RULES                                 #
####################################################################

all:	$(NAME)

$(NAME):	$(OBJS)
	@echo -n "$(COM_COLOR)compiling ft_printf... $(NO_COLOR)"
	@make -s --no-print-directory -C $(FT_PRINTF_PATH)
	@echo "$(COM_COLOR)done: $(OK_COLOR)[✓]$(NO_COLOR)"

	@make -s -C $(MLX_PATH)
	@echo -n "$(COM_COLOR)compiling mlx...       $(NO_COLOR)"
	@echo "$(COM_COLOR)done: $(OK_COLOR)[✓]$(NO_COLOR)"

	@echo -n "$(COM_COLOR)compiling $(NAME)...       $(NO_COLOR)"
	@$(CC) $(CFLAGS) $(OBJS) $(FT_PRINTFS) $(MLXS) -lX11 -lXext -o $(NAME) -I $(INCS)
	@echo "$(COM_COLOR)done: $(OK_COLOR)[✓]$(NO_COLOR)"

$(OBJ_PATH)%.o:	$(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(INCS)

clean:
	@rm -rf $(OBJ_PATH)
	@echo "$(COM_COLOR)clean:                       $(OK_COLOR)[✓]$(NO_COLOR)"
	@make -s --no-print-directory -C $(FT_PRINTF_PATH) clean
	@make -s --no-print-directory -C $(MLX_PATH) clean
	@echo "$(COM_COLOR)clean mlx:                   $(OK_COLOR)[✓]$(NO_COLOR)"

fclean:
	@rm -rf $(OBJ_PATH)
	@rm -f $(NAME)
	@echo "$(COM_COLOR)fclean:                      $(OK_COLOR)[✓]$(NO_COLOR)"
	@make -s --no-print-directory -C $(FT_PRINTF_PATH) fclean
	@make -s --no-print-directory -C $(MLX_PATH) clean
	@echo "$(COM_COLOR)clean mlx:                   $(OK_COLOR)[✓]$(NO_COLOR)"

re: fclean all

####################################################################
#                            COLORS                                #
####################################################################

COM_COLOR   = \033[0;34m
OK_COLOR    = \033[0;32m
NO_COLOR    = \033[m
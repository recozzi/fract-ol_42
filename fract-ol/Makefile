.SILENT:

MAKEFLAGS		+= --silent

NAME			:=	fractol

CC				:=	gcc

CFLAGS			:=	-g -Wall -Wextra -Werror -O3

MLXFLAGS		:=	-L minilibx-linux -lmlx -lm -lXext -lX11

RM				:=	rm -rf

LIBFT			:=	Libft/libft.a

OBJS_DIR		:=	obj/

SRCS_DIR		:=	src/

SRCS			:=	main.c			\
					init.c			\
					check_args.c	\
					create_img.c	\
					mandelbrot.c	\
					hooks_handler.c	\
					julia.c			\
					zoom.c			\
					burningship.c	\
					ft_color.c

OBJS			:=	$(addprefix $(OBJS_DIR), $(SRCS:.c=.o))

# COLORS ================================================================= #

RED		=	\033[0;91m
GREEN	=	\033[0;92m
YELLOW	=	\033[0;93m
WHITE	=	\033[0;97m

# ======================================================================== #

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
			@mkdir -p $(dir $@)
			@$(CC) $(CFLAGS) -c $< -o $@
			@echo "$(GREEN)Compiling:$(WHITE) $<"

all: $(NAME)

$(NAME): lib $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(MLXFLAGS) $(LIBFT) -o $(NAME)
	@echo "$(YELLOW)- Program Name: $(WHITE)${NAME}"
	@echo "$(YELLOW)- Compiler: $(WHITE)${CC}"
	@echo "$(YELLOW)- Flags: $(WHITE)${CFLAGS}"

lib:
	@make -C Libft

clean:
	@$(RM) $(OBJS)
	@make clean -C Libft
	@echo "$(RED)All object files removed.$(WHITE)"

fclean: clean
	@$(RM) $(NAME) $(OBJS_DIR)
	@make fclean -C Libft

re: fclean all

.PHONY: all clean fclean re lib

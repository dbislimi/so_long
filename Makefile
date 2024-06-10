LIBFT = ./libft
SL_PATH = ./srcs/so_long
BONUS_PATH = ./srcs/bonus
SRCS = ${addprefix ${SL_PATH}/,main.c move_utils.c parsing.c so_long_utils.c parsing_utils.c parsing_utils2.c flood_fill.c \
		free.c events.c load_textures.c manage_textures.c move.c}
SRCS_B = ${addprefix ${BONUS_PATH}/,main.c move_utils.c parsing.c so_long_utils.c parsing_utils.c parsing_utils2.c flood_fill.c \
		free.c events.c load_textures.c manage_textures.c move.c sprite.c}
OBJS = ${SRCS:.c=.o}
OBJS_B = ${SRCS_B:.c=.o}

NAME = so_long
BONUS = so_long_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
INCLUDES = -Iincludes -I/usr/include -Imlx
MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11

all : ${NAME}

bonus : ${BONUS}

${NAME} : ${OBJS}
	${MAKE} --silent -C ${LIBFT}
	${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIBFT}/libft.a ${MLX_FLAGS}

${BONUS} : ${OBJS_B}
	${MAKE} --silent -C ${LIBFT}
	${CC} ${CFLAGS} -o ${BONUS} ${OBJS_B} ${LIBFT}/libft.a ${MLX_FLAGS}

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

clean:
	@${MAKE} clean --silent -C ${LIBFT}
	@${RM} ${OBJS} ${OBJS_B}
	@printf "MAKEFILE CLEAN\n"

fclean: clean
	@${MAKE} fclean --silent -C ${LIBFT}
	@${RM} ${NAME} ${BONUS}
	@printf "MAKEFILE FCLEAN\n"

re: fclean all

.PHONY: all clean fclean re
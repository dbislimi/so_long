LIBFT = ./libft
SL_PATH = ./srcs/so_long
SRCS = ${addprefix ${SL_PATH}/,main.c parsing.c so_long_utils.c parsing_utils.c parsing_utils2.c flood_fill.c \
		free.c events.c load_textures.c manage_textures.c move.c move_utils.c}
OBJS = ${SRCS:.c=.o}

NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
INCLUDES = -Iincludes -I/usr/include -Imlx
MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11

all : ${NAME}


${NAME} : ${OBJS}
	${MAKE} --silent -C ${LIBFT}
	${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIBFT}/libft.a ${MLX_FLAGS}

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

clean:
	@${MAKE} clean --silent -C ${LIBFT}
	@${RM} ${OBJS}
	@printf "MAKEFILE CLEAN\n"

fclean: clean
	@${MAKE} fclean --silent -C ${LIBFT}
	@${RM} ${NAME}
	@printf "MAKEFILE FCLEAN\n"

re: fclean all



.PHONY: all clean fclean re
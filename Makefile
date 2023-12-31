NAME 			= 	fract-ol

CC 				= 	gcc

BONUS			= 	fract-ol_bonus

INCLUDES		= 	includes/

LIBFT_INCLUDES 	= 	libft/includes/

LIBFT 			= 	libft

FILES 			= 	hooks		\
					init		\
					main		\
					math_utils	\
					render		\
					string_utils

SRCS 			= 	$(addsuffix .c, $(addprefix sources/, $(FILES)))

OBJS 			= 	${SRCS:.c=.o}

CFLAGS 			= 	-Wall -Wextra -Werror

# CURSOR MOVEMENTS
MOV_U			= 	\033[1A
MOV_D			= 	\033[1B
MOV_F			= 	\033[1C
MOV_B			= 	\033[1D

ERASE_ALL		= 	\033[0J

# COLORS 
YELLOW 			= 	\033[0;33m
GREEN 			= 	\033[0;32m
BLUE 			= 	\033[0;34m
RED				= 	\033[0;31m
PURPLE 			= 	\033[0;35m
CYAN 			= 	\033[0;36m
BLACK 			= 	\033[0;30
WHITE 			= 	\033[0;37m

RESET			= 	\033[0m

${NAME} : 	${OBJS}
		@echo "${GREEN} Compiling... ${RESET}"
		@make --no-print-directory -C libft/
		@make --no-print-directory -C mlx_linux/
		@${CC} ${CFLAGS} -I ${INCLUDES} -I ${LIBFT_INCLUDES} -Imlx_linux ${SRCS} -o ${NAME} -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -L ${LIBFT} -lft
		@echo "${MOV_U}${ERASE_ALL}${RED} Done ${RESET}"

%.o 	: %.c
		@${CC} ${CFLAGS} -I ${INCLUDES} -I ${LIBFT_INCLUDES} -I mlx_linux -c $< -o $@

all 	: 	${NAME}

clean 	:
		@make clean --no-print-directory -C libft/
		@make clean --no-print-directory -C mlx_linux/
		@rm -rf ${OBJS} ${BOBJS}
		@echo "${BLUE} Cleaned ${RESET}"

bonus: all
		@mv $(NAME) $(BONUS)

fclean	: clean
		@make fclean --no-print-directory -C libft/
		@rm -rf ${NAME}
		@rm -rf ${BONUS}

re		: fclean all

.PHONY	: all clean fclean re ${NAME}
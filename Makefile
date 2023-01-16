#-----------------VARIABLES------------------
# gcc -Wall -Wextra -Werror main.c ../MLX42/libmlx42.a -I include -lglfw -L /Users/mthea/.brew/opt/glfw/lib -o main
#--------------------------------------------
# VARIABLES FOR DOT C
SERVER		=	Verification_ber/get_next_line_utils.c Verification_ber/get_next_line.c Verification_ber/allocation_double_table.c \
				Verification_ber/verification_double_table.c Verification_ber/utils.c Verification_ber/flood_fill_and_all_verification.c \

FT_PRINTF	= ft_printf/ft_printf.c ft_printf/ft_void_percent.c ft_printf/ft_string_letters.c \
				ft_printf/ft_numbers_base_ten.c ft_printf/ft_numbers_base_sixteen.c ft_printf/ft_external_functions.c \

#--------------------------------------------
# VARIABLES FOR DOT O
SERVER_OBJ = $(SERVER:.c=.o)


FT_PRINTF_OBJ = $(FT_PRINTF:.c=.o)
#--------------------------------------------
# VARIABLES FOR DO A COMPILATION
CC = gcc 

CFLAGS = -Wall -Werror -Wextra 

FLAGS = -lmlx -framework OpenGL -framework AppKit

EXEC_SERVER	=	so_long


RM = rm -rf

#-----------------EXECUTING------------------
#--------------------------------------------

all : $(EXEC_SERVER)

$(EXEC_SERVER) : $(FT_PRINTF_OBJ) $(SERVER_OBJ)
	$(CC) $(CFLAGS) $(FLAGS) $(FT_PRINTF_OBJ) $(SERVER_OBJ) -o $(EXEC_SERVER)


clean :
	$(RM) $(SERVER_OBJ) $(FT_PRINTF_OBJ)

fclean :	clean
	$(RM) $(EXEC_SERVER) $(EXEC_CLIENT)

re :	fclean all

.PHONY :	all clean fclean re
#--------------------------------------------
#-----------------VARIABLES------------------
# gcc -Wall -Wextra -Werror main.c ../MLX42/libmlx42.a -I include -lglfw -L /Users/mthea/.brew/opt/glfw/lib -o main
#--------------------------------------------
# VARIABLES FOR DOT C
VERIFICATION = Verification/get_next_line_utils.c Verification/get_next_line.c Verification/allocation_double_table.c \
				Verification/verification_double_table.c Verification/utils.c Verification/flood_fill_and_all_verification.c \

IMAGES = Window_management/main.c Window_management/utils.c 

FT_PRINTF	= ft_printf/ft_printf.c ft_printf/ft_void_percent.c ft_printf/ft_string_letters.c \
				ft_printf/ft_numbers_base_ten.c ft_printf/ft_numbers_base_sixteen.c ft_printf/ft_external_functions.c \

#--------------------------------------------
# VARIABLES FOR DOT O
VERIFICATION_OBJ = $(VERIFICATION:.c=.o)

IMAGES_OBJ = $(IMAGES:.c=.o)

FT_PRINTF_OBJ = $(FT_PRINTF:.c=.o)
#--------------------------------------------
# VARIABLES FOR DO A COMPILATION
CC = gcc 

CFLAGS = -Wall -Werror -Wextra 

FLAGS = MLX42/libmlx42.a -I include -lglfw -L /Users/mthea/.brew/opt/glfw/lib

EXEC_SERVER	=	so_long


RM = rm -rf

#-----------------EXECUTING------------------
#--------------------------------------------

all : $(EXEC_SERVER)

$(EXEC_SERVER) : $(FT_PRINTF_OBJ) $(VERIFICATION_OBJ) $(IMAGES_OBJ)
	$(CC) $(CFLAGS) $(FLAGS) $(FT_PRINTF_OBJ) $(IMAGES_OBJ) $(VERIFICATION_OBJ) -o $(EXEC_SERVER)
# Rajouter verification du .ber et si la map contient que des '0' ou '1' ou 'C' ou 'G' ou 'P' ou 'E'

clean :
	$(RM) $(VERIFICATION_OBJ) $(FT_PRINTF_OBJ) $(IMAGES_OBJ)

fclean :	clean
	$(RM) $(VERIFICATION_OBJ) $(FT_PRINTF_OBJ) $(IMAGES_OBJ)

re :	fclean all

.PHONY :	all clean fclean re
#--------------------------------------------
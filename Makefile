NAME = fdf
SRC = main.c read.c drowx.c drowy.c 
LFT_PATH = libft/ft_atoi.c libft/ft_memalloc.c libft/ft_putstr.c \
libft/ft_bzero.c libft/ft_strjoin.c libft/ft_putchar.c libft/ft_strcat.c \
libft/ft_strcpy.c libft/ft_strlen.c
OUT = *.o
INC = /usr/local/include
MINI = -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit
FLAGS = -Wall -Wextra -Werror
all: $(NAME)

$(NAME):
	gcc  $(FLAGS) -o $(NAME)  $(SRC) $(MINI) $(LFT_PATH)
clean:
	rm -f $(OUT)
fclean:	clean
	rm -f $(NAME)
re: 	fclean all
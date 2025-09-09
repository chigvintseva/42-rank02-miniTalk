#final library name
NAME = printf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c \
	ft_charinput.c \
	ft_strinput.c \
	ft_intinput.c \
	ft_ptrinput.c \
	ft_nbrbase.c \
	ft_ltoa.c

OBJ = $(SRC:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all


.PHONY: all clean fclean re

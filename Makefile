# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achigvin <achigvin@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/10 13:55:39 by achigvin          #+#    #+#              #
#    Updated: 2025/09/15 17:19:13 by achigvin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CLIENT = client
NAME_SERVER = server

LIBFT = libft/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

# ---------

SRC_CLIENT = client.c message.c

OBJ_DIR_CLIENT = objects_client
OBJ_CLIENT = $(addprefix $(OBJ_DIR_CLIENT)/,$(SRC_CLIENT:.c=.o))

# ----------

SRC_SERVER = server.c handler.c

OBJ_DIR_SERVER = objects_server
OBJ_SERVER = $(addprefix $(OBJ_DIR_SERVER)/,$(SRC_SERVER:.c=.o))


# -------- name rule --------
all: $(NAME_CLIENT) $(NAME_SERVER)


# --------- client-----------
$(NAME_CLIENT): $(OBJ_CLIENT) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ_CLIENT) $(LIBFT) -o $@

$(OBJ_DIR_CLIENT):
	mkdir -p $(OBJ_DIR_CLIENT)
	
$(OBJ_DIR_CLIENT)/%.o: %.c | $(OBJ_DIR_CLIENT)
	$(CC) $(CFLAGS) -c $< -o $@


# --------- server -----------
$(NAME_SERVER): $(OBJ_SERVER) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ_SERVER) $(LIBFT) -o $@

$(OBJ_DIR_SERVER):
	mkdir -p $(OBJ_DIR_SERVER)
	
$(OBJ_DIR_SERVER)/%.o: %.c | $(OBJ_DIR_SERVER)
	$(CC) $(CFLAGS) -c $< -o $@



# ------ libft compilation, -C flag is for "change directory to the subdirectory libft"
$(LIBFT):
	$(MAKE) -C libft
	

# --------- clean fclean re rules-----------
clean:
	rm -f $(OBJ_CLIENT) $(OBJ_SERVER)
	$(MAKE) -C libft clean

fclean: clean
	rm -f $(NAME_SERVER) $(NAME_CLIENT) 
	$(MAKE) -C libft fclean
	rm -rf $(OBJ_DIR_CLIENT) $(OBJ_DIR_SERVER)

re: fclean all

# -------------------

.PHONY: all clean fclean re

-include $(DEP)
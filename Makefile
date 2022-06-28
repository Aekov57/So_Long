# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: misimon <misimon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/28 15:43:40 by misimon           #+#    #+#              #
#    Updated: 2022/06/28 17:42:57 by misimon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g3
DANGER = -fsanitize=address
LIBS = -lmlx -framework OpenGL -framework AppKit \
	-Llibft -lft #ajouter la libft

# ============================================================================ #
# ==============================|	FILES	|================================= #
# ============================================================================ #

SL_SRC = main\
		 readmap\

ALL_SRC +=	$(addsuffix .c, $(SL_SRC))

OBJS = $(ALL_SRC:.c=.o)

# ============================================================================ #
# ==============================|	 CMD	|================================= #
# ============================================================================ #

all : $(NAME)

.c.o :
	@$(CC) $(CFLAGS) -o $@ -c $<

$(NAME) : $(OBJS)
	@make -sC libft
	$(CC) $(DANGER) -o $(NAME) $(OBJS) $(LIBS)

norm :
	@make norm -sC libft
	@norminette

clean :
	@make clean -sC libft
	@rm -f $(OBJS)

fclean : clean
	@make fclean -sC libft
	@rm -f $(NAME)

re : fclean all

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: misimon <misimon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/28 15:43:40 by misimon           #+#    #+#              #
#    Updated: 2022/09/28 19:10:42 by misimon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g3
DANGER = -fsanitize=address
LIBS =  mlx/libmlx42.a -I include -lglfw -L "/Users/misimon/.brew/opt/glfw/lib/"\
		-Llibft -lft #ajouter la libft

# -Lmlx -lmlx -framework OpenGL -framework AppKit
# -lmlx -framework OpenGL -framework AppKit
# ============================================================================ #
# ==============================|	FILES	|================================= #
# ============================================================================ #

SL_SRC = main\
		success_fct\
		error_fct\
		read_map\
		other_fct\
		check_map\
		texture_fct\
		move_fct\
		check_access\

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
	@make -sC mlx
	$(CC) -o $(NAME) $(OBJS) $(LIBS) $(DANGER)
norm :
	@make norm -sC libft
	@norminette

clean :
	@make clean -sC libft
	@make clean -sC mlx
	@rm -f $(OBJS)

fclean : clean
	@make fclean -sC libft
	@rm -f $(NAME)

re : fclean all

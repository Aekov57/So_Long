# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: misimon <misimon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/01 18:29:09 by misimon           #+#    #+#              #
#    Updated: 2022/06/28 15:11:11 by misimon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = @gcc
CFLAGS = -Wall -Werror -Wextra

# ============================================================================ #
# ==============================|	FILES	|================================= #
# ============================================================================ #

CHECK_SRC =	ft_isalpha\
			ft_isdigit\
			ft_isprint\
			ft_isascii\
			ft_isalnum\

ALL_SRC += $(addprefix CheckFunction/, $(addsuffix .c, $(CHECK_SRC)))

# ============================================================================ #

CONVERT_SRC =	ft_atoi\
				ft_bzero\
				ft_itoa\
				ft_split\
				ft_tolower\
				ft_toupper\

ALL_SRC += $(addprefix ConvertFunction/, $(addsuffix .c, $(CONVERT_SRC)))

# ============================================================================ #

MEM_SRC =	ft_memmove\
			ft_memcpy\
			ft_memset\
			ft_memcmp\
			ft_memccpy\
			ft_memchr\
			ft_calloc\

ALL_SRC += $(addprefix MemFunction/, $(addsuffix .c, $(MEM_SRC)))

# ============================================================================ #

PUT_SRC =	ft_putchar_fd\
			ft_putstr_fd\
			ft_putnbr_fd\
			ft_putendl_fd\

ALL_SRC += $(addprefix PutFunction/, $(addsuffix .c, $(PUT_SRC)))

# ============================================================================ #

STR_SRC =	ft_strchr\
			ft_strlcat\
			ft_strlcpy\
			ft_strlen\
			ft_strrchr\
			ft_strncmp\
			ft_strnstr\
			ft_strdup\
			ft_substr\
			ft_strtrim\
			ft_strjoin\
			ft_strmapi\
			ft_striteri\

ALL_SRC += $(addprefix StrFunction/, $(addsuffix .c, $(STR_SRC)))

# ============================================================================ #

PRINTF_SRC = ft_printf_hex\
			 ft_printf_other\
			 ft_printf_ptr\
			 ft_printf_uint\
			 ft_printf

ALL_SRC += $(addprefix Ft_Printf/, $(addsuffix .c, $(PRINTF_SRC)))

# ============================================================================ #

GNL_SRC = get_next_line_utils\
		  get_next_line\

ALL_SRC += $(addprefix GetNextLine/, $(addsuffix .c, $(GNL_SRC)))

OBJS = $(ALL_SRC:.c=.o)

# ============================================================================ #
# ==============================|	 CMD	|================================= #
# ============================================================================ #

all : $(NAME)

$(NAME) : $(OBJS)
	@ar rc $(NAME) $(OBJS)


norm :
	@norminette

clean :
	@rm -f $(OBJS)

fclean : clean
	@rm -f $(NAME)

re : fclean all

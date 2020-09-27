# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aenstein <aenstein@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/02 19:36:59 by aenstein          #+#    #+#              #
#    Updated: 2020/09/19 22:02:31 by aenstein         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: clean fclean re all obj

NAME := aenstein.filler

CC := gcc 
FLAGS := -Wall -Wextra -Werror -g

LIB := ./lib/
FT_LIB := $(addprefix $(LIB),libftprintf.a)
FT_INK := -I ./lib
FT_LNK := -L ./lib/ -lftprintf

DIR_S := ./sources/
DIR_O := ./objects/
HEADER := ./includes/

SOURCES :=	heat_map.c \
			init_and_free_fun.c \
			main.c \
			parse_players.c \
			piece.c \
			plateau.c \
			solver.c \
			
OBJS := $(addprefix $(DIR_O),$(SOURCES:.c=.o))

all: obj $(FT_LIB) $(NAME)

obj:
		mkdir -p $(DIR_O)
$(DIR_O)%.o:$(DIR_S)%.c
		$(CC) $(FLAGS) $(FT_INK) $(FT_INK) -I $(HEADER) -o $@ -c $<

$(FT_LIB):
		make -C $(LIB)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME) $(FT_LNK)

clean:
		rm -rf $(DIR_O)
		make -C $(LIB) clean

fclean: clean
		rm -rf $(NAME)
		make -C $(LIB) fclean

re: fclean all
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgarault <fgarault@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/27 08:10:12 by fgarault          #+#    #+#              #
#    Updated: 2024/04/27 19:01:02 by fgarault         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	ft_ssl

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror

RED		=	\033[1;31m
GREEN	=	\033[1;32m
YELLOW	=	\033[1;33m
PURPLE	=	\033[1;34m
BLUE	=	\033[1;36m
WHITE	=	\033[1;39m
RESET	=	\033[0m

LIBDIR	=	libft
LIBFT	= 	$(LIBDIR)/libft.a
DIR		=	src
SRC		=	ft_ssl.c parsing.c md5.c

OBJDIR	=	obj
OBJ	=	$(addprefix $(OBJDIR)/, $(SRC:.c=.o))

all : $(NAME)

$(NAME) : $(LIBFT) $(OBJ) 
	$(CC) $(CFLAGS) $^ -o $(NAME) 

$(LIBFT) :
	@make -C $(LIBDIR)

$(OBJ) : $(OBJDIR)

$(OBJDIR)/%.o: $(DIR)/%.c
	$(CC) $(CFLAGS) -c $< -I $(DIR)/ft_ssl.h -o $@ 

$(OBJDIR) :
	@mkdir $@

clean :
	@rm -rf $(OBJDIR)
	@rm -rf $(LIBDIR)/$(OBJDIR)

fclean : clean
	@rm $(NAME)
	@rm $(LIBFT)

re : fclean all

.PHONY: clean fclean re all
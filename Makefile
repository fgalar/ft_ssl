# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgarault <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/07 17:50:20 by fgarault          #+#    #+#              #
#    Updated: 2020/12/21 19:05:23 by fgarault         ###   ########.fr        #
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

MLIBFT	= make -C libft

# INCLUDE	=	ft_ssl.h
DIR		=	srcs
SRC	=	ft_ssl.c

OBJDIR	=	obj
OBJS	=	$(addprefix $(OBJDIR)/, $(SRC:.c=.o))

all : $(NAME)

$(NAME) : $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $(NAME) 

$(OBJ) : | $(OBJDIR)

$(OBJDIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INLCUDE)

$(OBJDIR) :
	mkdir $@

$(LIBFT) :
	make -C $(LIBDIR)

clean :
	rm -rf $(OBJDIR)
	make clean -C $(LIBDIR)

fclean : clean
	rm $(NAME)
	make fclean -C $(LIBDIR)

re : fclean all
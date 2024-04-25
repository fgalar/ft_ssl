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

NAME	=	libft.a

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror

INCLUDE	=	libft.h

RED		=	\033[1;31m
GREEN	=	\033[1;32m
YELLOW	=	\033[1;33m
PURPLE	=	\033[1;34m
BLUE	=	\033[1;36m
WHITE	=	\033[1;39m
RESET	=	\033[0m

LIBCDIR	=	libc
SRCS	=	ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c	\
			ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c		\
			ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c	\
			ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c	\
			ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c	\
			ft_isprint.c ft_toupper.c ft_tolower.c ft_memalloc.c ft_memdel.c\
			ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c	\
			ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c	\
			ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar.c	\
			ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c 			\
			ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c		\
			ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c	ft_lstmap.c	\
			ft_nbrlen.c ft_print_tab.c ft_print_tab_int.c ft_power.c 		\
			ft_sort_integer.c ft_itoa_base.c get_next_line.c ft_utoa.c		\
			ft_ismaj.c ft_strndup.c gnl.c

PFDIR	=	ft_printf
PFHEADER=	ft_printf.h
PFSRC	=	ft_printf.c dispatcher.c parsing.c print_c.c print_s.c print_p.c\
		 	print_d.c print_o.c print_u.c print_x.c print_f.c ft_ftoa.c		\
			handle_arg.c ft_buffer.c tools.c tools2.c

OBJDIR	=	objs
OBJS	=	$(addprefix $(OBJDIR)/, $(SRCS:.c=.o))
PFOBJS	=	$(addprefix $(OBJDIR)/, $(PFSRC:.c=.o))

all : $(NAME)

$(OBJDIR) :
	@mkdir $@
$(OBJDIR)/%.o: $(LIBCDIR)/%.c 
	@echo "$(YELLOW)Making object : $(PURPLE)$@$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDE)
$(OBJDIR)/%.o: $(PFDIR)/%.c
	@echo "$(YELLOW)Making object : $(PURPLE)$@$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(PFHEADER)

$(NAME) : $(OBJDIR) $(OBJS) $(PFOBJS)
	@ar rcs $(NAME) $(OBJS) $(PFOBJS)
	@ranlib $(NAME)
	@echo "$(GREEN)[libft.a] compiled with success $(RESET)"

norme :
	@norminette -R $(LIBCDIR)/$(SRCS) $(PFDIR)/$(PFSRCS) $(LIBCDIR)/$(INCLUDE) $(PFDIR)/$(PFHEADER)

clean :
	@rm -rf $(OBJDIR)
	@echo "$(RED)Objects of libft are deleted$(RESET)"

fclean : clean
	@rm -f $(NAME)
	@echo "$(RED)[libft.a] is deleted$(RESET)"

re : fclean all

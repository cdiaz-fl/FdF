# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdiaz-fl <cdiaz-fl@student.42urduliz.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/29 18:08:14 by cdiaz-fl          #+#    #+#              #
#    Updated: 2021/11/30 11:54:02 by cdiaz-fl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	ft_memset.c        \
        ft_bzero.c        \
        ft_memcpy.c       \
        ft_memccpy.c      \
        ft_memmove.c		\
        ft_memchr.c        \
        ft_memcmp.c        \
        ft_strlen.c        \
        ft_isalpha.c    	\
        ft_isdigit.c        \
        ft_isalnum.c        \
        ft_isascii.c        \
        ft_isprint.c        \
        ft_toupper.c        \
        ft_tolower.c        \
        ft_strchr.c        \
        ft_strrchr.c        \
        ft_strncmp.c        \
        ft_strlcpy.c        \
        ft_strlcat.c        \
        ft_strnstr.c        \
        ft_atoi.c        \
        ft_calloc.c        \
        ft_strdup.c        \
		ft_strtrim.c	\
		ft_substr.c		\
		ft_putchar_fd.c		\
		ft_putstr_fd.c		\
		ft_putendl_fd.c		\
		ft_putnbr_fd.c		\
		ft_strjoin.c		\
		ft_itoa.c		\
		ft_split.c		\
		ft_strmapi.c	\
		get_next_line_bonus.c	\
		get_next_line_utils_bonus.c	\

BONS = ft_lstnew.c		\
	   ft_lstadd_front.c\
	   ft_lstsize.c		\
	   ft_lstlast.c		\
	   ft_lstadd_back.c	\
	   ft_lstdelone.c	\
	   ft_lstclear.c	\
	   ft_lstiter.c		\
	   ft_lstmap.c		\


NAME = libft.a

OBJS = $(SRCS:.c=.o)

BOBJS = $(BONS:.c=.o)

CC = clang

C_FLAGS = -Wall -Wextra -Werror

AR = ar rcs

RANLIB = ranlib

LFLAGS = -I

$(NAME):	$(OBJS)
			@$(AR) $(NAME) $(OBJS)
			@$(RANLIB) $(NAME)

bonus:		$(OBJS) $(BOBJS) 
			@$(AR) $(NAME) $(OBJS) $(BOBJS)
			@$(RANLIB) $(NAME)

all: 		$(NAME)

clean:
		rm -rf $(OBJS)
		rm -rf $(BOBJS)

fclean: clean
		rm -f $(NAME)

re:		fclean all

.SILENT: all clean fclean bonus $(NAME)

.PHONY:	all clean fclean


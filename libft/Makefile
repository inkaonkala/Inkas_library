# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iniska <iniska@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/06 11:48:58 by iniska            #+#    #+#              #
#    Updated: 2023/11/07 14:47:18 by iniska           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC =  \
	  ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c  ft_isalpha.c \
	  ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c \
	  ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
	  ft_putendl_fd.c ft_putstr_fd.c ft_strdup.c ft_strchr.c \
	  ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c \
	  ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_toupper.c \
	  ft_strtrim.c ft_substr.c ft_tolower.c ft_split.c ft_putnbr_fd.c \
	  ft_form.c \ ft_printf.c \ print_address.c \ print_digit.c \ printchar.c \
	  printstr.c \ get_next_line.c \ get_next_line_utils.c \
	  morehelpers.c


BONUS_SRC = \
		   	ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c \
			ft_lstdelone_bonus.c ft_lstlast_bonus.c ft_lstnew_bonus.c \
			ft_lstsize_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

OBJ = $(SRC:.c=.o)

BONUS_OBJ = $(BONUS_SRC:.c=.o)

CC = gcc

AR = ar

CFLAGS	= -Wall -Wextra -Werror

all:	$(NAME)

$(NAME): $(OBJ)
	$(AR) -r $@ $?

bonus: $(OBJ) $(BONUS_OBJ)
	$(AR) -r $(NAME) $?

%.o: %.c
	$(CC) -c $(CFLAGS) $?

clean:
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:  all bonus clean fclean re

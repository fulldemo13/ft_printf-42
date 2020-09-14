# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fulldemo <fulldemo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/09 09:59:06 by fulldemo          #+#    #+#              #
#    Updated: 2019/12/14 08:58:38 by fulldemo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a
SRC			=	ft_atoi.c \
				ft_strlen.c \
				ft_putnchar.c \
				ft_putnstr.c \
				ft_putnbr.c \
				ft_printf.c \
				ft_checkflags.c \
				ft_conversors.c \
				ft_string.c \
				ft_char.c \
				ft_numbers.c \
				ft_pointer.c \
				ft_putptr.c \
				ft_unsigned_number.c \
				ft_hexanumbers.c \
				ft_puthexa.c \
				ft_simple.c
 
OBJ			= 	${SRC:.c=.o}
CC			= 	gcc
RM			= 	rm -f
CFLAG		= 	-c -Wall -Wextra -Werror
CCTWO		=	ar rc

all:		${NAME}
${NAME}:	${OBJ}
			${CCTWO} ${NAME} ${OBJ}

ft_%.o: ft_%.c
	${CC} ${CFLAG} $<
clean:
			${RM} *.o
fclean:		clean
			${RM} ${NAME}
re:			fclean all
.PHONY:		all clean fclean re 
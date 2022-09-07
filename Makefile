# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: serodrig <serodrig@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/21 16:59:05 by serodrig          #+#    #+#              #
#    Updated: 2022/08/04 13:03:12 by serodrig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

SRCS 	=	ft_printf.c conversion.c utils.c

OBJS	=	${SRCS:.c=.o}

CC		= 	gcc

CFLAGS	= 	-Wall -Wextra -Werror

RM		=	rm -f

all: ${NAME}

${NAME}:
			${CC} ${CFLAGS} -c ${SRCS} -I./
			ar rc ${NAME} ${OBJS}
	
clean:
			${RM} ${OBJS}

fclean: clean
			${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re

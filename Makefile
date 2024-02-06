# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/26 13:26:47 by mbrousse          #+#    #+#              #
#    Updated: 2024/02/06 17:15:59 by mbrousse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES_SERVER	=	server.c\
					server_utils.c

SOURCES_CLIENT	=	client.c\
					client_utils.c

OBJECTS_SERVER	= 	${SOURCES_SERVER:.c=.o}

OBJECTS_CLIENT	= 	${SOURCES_CLIENT:.c=.o}

HEADER			=	project.h

SERVER			=	server

CLIENT			=	client

CC 				=	cc

FLAGS 			=	-Wall -Wextra -Werror

all: ${CLIENT} ${SERVER}

%.o:%.c  ${HEADER} libft/libft.h
	@${CC} ${FLAGS} -c $< -o $@

${CLIENT}: ${OBJECTS_CLIENT} Makefile
	@make -C ./libft
	@${CC} ${FLAGS} ${OBJECTS_CLIENT} -o ${CLIENT} -L./libft -lft

${SERVER}: ${OBJECTS_SERVER} Makefile
	@make -C ./libft	
	@${CC} ${FLAGS} ${OBJECTS_SERVER} -o ${SERVER} -L./libft -lft

clean:
	@make clean -C ./libft
	@rm -f ${OBJECTS_CLIENT} ${OBJECTS_SERVER} 

fclean: clean
	@make fclean -C ./libft
	@rm -f ${CLIENT} ${SERVER}

re: fclean all

.PHONY: all clean fclean re
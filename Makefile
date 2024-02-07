# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/26 13:26:47 by mbrousse          #+#    #+#              #
#    Updated: 2024/02/07 15:17:01 by mbrousse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HEADER				=	project.h

SERVER				=	server

CLIENT				=	client

CC 					=	cc

FLAGS 				=	-Wall -Wextra -Werror

SOURCES_SERVER		=	server.c\
						server_utils.c

SOURCES_CLIENT		=	client.c\
						client_utils.c


OBJECTS_SERVER		= 	${SOURCES_SERVER:.c=.o}

OBJECTS_CLIENT		= 	${SOURCES_CLIENT:.c=.o}

# BONUS
H_B					=	project_bonus.h

O_S_B		= 	${S_S_B:.c=.o}

O_C_B		= 	${S_C_B:.c=.o}

S_S_B				=	server_bonus.c\
						server_utils_bonus.c

S_C_B				=	client_bonus.c\
						client_utils_bonus.c

S_B					=	server_bonus

C_B					=	client_bonus

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
	@rm -f ${OBJECTS_CLIENT} ${OBJECTS_SERVER} ${O_C_B} ${O_S_B}

fclean: clean
	@make fclean -C ./libft
	@rm -f ${CLIENT} ${SERVER} ${C_B} ${S_B}

re: fclean all

bonus:
	@make HEADER="${H_B}" SERVER="${S_B}" CLIENT="${C_B}" SOURCES_SERVER="${S_S_B}" SOURCES_CLIENT="${S_C_B}"

.PHONY: all clean fclean re bonus
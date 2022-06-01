# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rel-hach <rel-hach@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/14 15:25:09 by rel-hach          #+#    #+#              #
#    Updated: 2022/05/16 16:43:18 by rel-hach         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = client
SERVER = server
CFLAGS = -Wall -Wextra -Werror
CC = cc
SRC_CLIENT = client.c

SRC_SERVER = server.c \
	
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
OBJ_SERVER = $(SRC_SERVER:.c=.o)

all : $(SERVER) $(CLIENT)


$(SERVER): $(OBJ_SERVER) 
	@$(CC) $(CFLAGS) $(OBJ_SERVER) -o $(SERVER) 
	
$(CLIENT): $(OBJ_CLIENT) 
	@$(CC) $(CFLAGS) $(OBJ_CLIENT) -o $(CLIENT)

clean :
	@rm -rf $(OBJ_CLIENT) $(OBJ_SERVER)

fclean : clean
	@rm -rf $(CLIENT)
	@rm -rf $(SERVER)

re : fclean all

.SILENT:all re
 
.PHONY : clean fclean re

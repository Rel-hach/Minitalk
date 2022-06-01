# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rel-hach <rel-hach@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/14 15:25:09 by rel-hach          #+#    #+#              #
#    Updated: 2022/05/17 12:18:41 by rel-hach         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = client_bonus
SERVER = server_bonus
CFLAGS = -Wall -Wextra -Werror
CC = cc
SRC_CLIENT = client_bonus.c

SRC_SERVER = server_bonus.c \
	  	server_utils.c \
	
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
OBJ_SERVER = $(SRC_SERVER:.c=.o)

bonus : $(SERVER) $(CLIENT)

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

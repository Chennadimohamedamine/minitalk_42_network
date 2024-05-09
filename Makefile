FILE = 	utils.c

SRCSERVER = server.c $(FILE)
SRCCLIENT =  client.c $(FILE)

SRCSERVER_BONUS = server_bonus.c $(FILE)
SRCCLIENT_BONUS =  client_bonus.c $(FILE)

OBJ_C = $(SRCCLIENT:%.c=%.o)
OBJ_S = $(SRCSERVER:%.c=%.o)
OBJ_C_BONUS = $(SRCCLIENT_BONUS:%.c=%.o)
OBJ_S_BONUS = $(SRCSERVER_BONUS:%.c=%.o)

all : client server

server : $(OBJ_S)
	cc -Wall -Wextra -Werror $(OBJ_S) -o server

client : $(OBJ_C)
	cc -Wall -Wextra -Werror $(OBJ_C) -o client

bonus : client_bonus server_bonus

%.o: %.c minitalk.h
	cc -Wall -Wextra -Werror -o $@ -c $<

server_bonus : $(OBJ_S_BONUS)
	cc -Wall -Wextra -Werror $(OBJ_S_BONUS) -o server_bonus
client_bonus : $(OBJ_C_BONUS)
	cc -Wall -Wextra -Werror $(OBJ_C_BONUS) -o client_bonus

clean :
	rm -f $(OBJ_S) $(OBJ_C)
	rm -f $(OBJ_S_BONUS) $(OBJ_C_BONUS)

fclean : clean
	rm -f client server 
	rm -f client_bonus server_bonus
re:	fclean all

.PHONY: all clean fclean re
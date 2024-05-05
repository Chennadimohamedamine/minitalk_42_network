FILE = 	utils.c
SRCSERVER = server.c $(FILE)
SRCCLIENT =  client.c $(FILE)
OBJ_C = $(SRCCLIENT:%.c=%.o)
OBJ_S = $(SRCSERVER:%.c=%.o)

all : client server

server : $(OBJ_S)
	cc -Wall -Wextra -Werror $(OBJ_S) -o server

client : $(OBJ_C)
	cc -Wall -Wextra -Werror $(OBJ_C) -o client

%.o: %.c minitalk.h
	cc -Wall -Wextra -Werror -o $@ -c $<

clean :
	rm -f $(OBJ_S) $(OBJ_C)

fclean : clean
	rm -f client server
re:	fclean all

.PHONY: all clean fclean re
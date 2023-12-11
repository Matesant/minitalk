CC := cc
FLAGS := -Wall -Werror -Wextra
SRC := client.c
SRC2 := server.c

all: $(SRC)
	$(CC) $(FLAGS) $(SRC2) -o server
	$(CC) $(FLAGS) $(SRC) -o client
CC = cc
SERVER = server
CLIENT = client
CFLAGS	:= -Wextra -Wall -Werror

SOURCE_SERVER	:=  sources/server.c

SOURCE_CLIENT	:=  sources/client.c

PRINTF:= ./Printf/libftprintf.a
LIBFT:= ./42_libft/libft.a
PRINTF := ./Printf/libftprintf.a

BLUE = \033[1;34m
RED=\033[0;31m
GREEN=\033[0;32m
END=\033[0m

all: $(LIBFT) $(PRINTF) $(SERVER) $(CLIENT)

$(LIBFT):
	@printf "$(BLUE)Compiling Libft...$(END)\n"
	@make -C ./42_libft --no-print-directory

$(PRINTF):
	@printf "$(BLUE)Compiling Printf...$(END)\n"
	@make -C ./Printf --no-print-directory

$(SERVER): $(SOURCE_SERVER)
	@printf "$(BLUE)Compiling $(SERVER)...$(END)\n"
	@$(CC) $(CFLAGS) $(SOURCE_SERVER) -L 42_libft -lft -o $(SERVER)

$(CLIENT): $(SOURCE_CLIENT)
	@printf "$(BLUE)Compiling $(CLIENT)...$(END)\n"
	@$(CC) $(CFLAGS) $(SOURCE_CLIENT) -L 42_libft -lft -o $(CLIENT)
	@echo "$(GREEN)$(SERVER) and $(CLIENT) are ready to use!$(END)\n"

clean:
	@printf "$(RED)Cleaning...$(END)\n"
	@make -C ./Printf clean --no-print-directory
	@make -C ./42_libft clean --no-print-directory

fclean: 
	@printf "$(RED)Cleaning...$(END)\n"
	@make -C ./Printf --no-print-directory fclean
	@make -C ./42_libft --no-print-directory fclean
	@rm -rf $(SERVER)
	@rm -rf $(CLIENT)

re: fclean all

.PHONY: all clean fclean re
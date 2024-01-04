CC = cc
SERVER = server
SERVER_BONUS = server_bonus
CLIENT = client
CLIENT_BONUS = client_bonus
CFLAGS	:= -Wextra -Wall -Werror

SOURCE_SERVER	:=  ./sources/server.c

SOURCE_CLIENT	:=  ./sources/client.c

SOURCE_SERVER_BONUS	:=  ./sources/server_bonus.c

SOURCE_CLIENT_BONUS	:=  ./sources/client_bonus.c

HEADER	:= ./includes/minitalk.h

PRINTF:= ./Printf/libftprintf.a
LIBFT:= ./42_libft/libft.a
42LIBS:= $(PRINTF) $(LIBFT)

BLUE = \033[1;34m
RED=\033[0;31m
GREEN=\033[0;32m
END=\033[0m

all: $(LIBFT) $(PRINTF) $(SERVER) $(CLIENT)

bonus: $(LIBFT) $(PRINTF) $(SERVER_BONUS) $(CLIENT_BONUS)

$(LIBFT):
	@printf "$(BLUE)Compiling Libft...$(END)\n"
	@make -C ./42_libft --no-print-directory

$(PRINTF):
	@printf "$(BLUE)Compiling Printf...$(END)\n"
	@make -C ./Printf --no-print-directory

$(SERVER): $(SOURCE_SERVER)
	@printf "$(BLUE)Compiling $(SERVER)...$(END)\n"
	@$(CC) $(CFLAGS) $(SOURCE_SERVER) $(42LIBS) -o $(SERVER)

$(CLIENT): $(SOURCE_CLIENT)
	@printf "$(BLUE)Compiling $(CLIENT)...$(END)\n"
	@$(CC) $(CFLAGS) $(SOURCE_CLIENT) $(42LIBS) -o $(CLIENT)
	@echo "$(GREEN)$(SERVER) and $(CLIENT) are ready to use!$(END)\n"

$(SERVER_BONUS): $(SOURCE_SERVER_BONUS)
	@printf "$(BLUE)Compiling $(SERVER_BONUS)...$(END)\n"
	@$(CC) $(CFLAGS) $(SOURCE_SERVER_BONUS) $(42LIBS) -o $(SERVER_BONUS)

$(CLIENT_BONUS): $(SOURCE_CLIENT_BONUS)
	@printf "$(BLUE)Compiling $(CLIENT_BONUS)...$(END)\n"
	@$(CC) $(CFLAGS) $(SOURCE_CLIENT_BONUS) $(42LIBS) -o $(CLIENT_BONUS)
	@echo "$(GREEN)$(SERVER_BONUS) and $(CLIENT_BONUS) are ready to use!$(END)\n"

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
	@rm -rf $(SERVER_BONUS)
	@rm -rf $(CLIENT_BONUS)
	@printf "$(GREEN)All cleaned!$(END)\n"

re: fclean all

.PHONY: all bonus clean fclean re
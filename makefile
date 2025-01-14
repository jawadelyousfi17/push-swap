CC = cc
SRC = instructions1.c parse_args.c stack.c push_swap.c errors_handler.c free_matrix.c  utils.c

GREEN= \033[0;32m
NC= \033[0m 


LIBS = libft/libft.a

OBJS = $(SRC:.c=.o)

NAME = push_swap

all: libft $(NAME)
	@echo "✅ $(GREEN)Build complete.$(NC)"
	@echo "$(GREEN)▶️ Run ./$(NAME) <ARGS>$(NC)"

$(NAME): $(OBJS)
	@echo "🔗 Linking object files into $(NAME)..."
	@$(CC) $(OBJS) $(LIBS) -o $(NAME)

%.o: %.c push_swap.h
	@echo "🛠 Compiling $< ..."
	@$(CC) -c $< -o $@

libft:
	@make -C libft

clean:
	@echo "🗑️ Cleaning object files..."
	@rm -rf $(OBJS)

fclean: clean
	@echo "🗑️ Cleaning all generated files..."
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re libft

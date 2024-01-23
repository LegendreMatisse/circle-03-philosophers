NAME		=	philo
LIBRARY		=	philo.a

CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra -g
AR			=	ar rcs
RM			=	rm -rf

SRCS		=	philosophers.c

OBJ_DIR		=	obj
OBJS		=	$(SRCS:%.c=$(OBJ_DIR)/%.o)

GREEN		=	\e[0;46m
YELLOW		=	\e[0;226m
RESET		=	\033[0m

print-colors:
		@for code in $$(seq 100 231); do \
			$(call PRINT_COLOR_LINE,$$code); \
		done

$(OBJ_DIR)/%.o:	%.c
				@$(CC) $(CFLAGS) -c $< -o $@
				@echo "$(YELLOW)Compiling $<...$(RESET)"

all:		$(NAME)

$(NAME):	$(LIBFT) $(OBJ_DIR) $(OBJS)
			@echo "$(YELLOW)Creating $(LIBRARY) archive...$(RESET)"
			@$(AR) $(LIBRARY) $(OBJS) >/dev/null 2>&1
			@echo "$(YELLOW)Linking $(NAME) executable...$(RESET)"
			@$(CC) -o $(NAME) $(LIBRARY)
			@echo "$(GREEN)$(NAME) is ready.$(RESET)"

$(OBJ_DIR):
			@mkdir -p $(OBJ_DIR)
			@echo "$(YELLOW)Creating the objects directory...$(RESET)"

clean:
			@$(RM) $(OBJ_DIR) >/dev/null 2>&1
			@$(RM) *.0 >/dev/null 2>&1
			@echo "$(YELLOW)Cleaning all .o files.$(RESET)"

fclean:		clean
			@$(RM) $(LIBRARY) >/dev/null 2>&1
			@$(RM) $(NAME) >/dev/null 2>&1
			@$(RM) *.a >/dev/null 2>&1
			@echo "$(YELLOW)Cleaning all .a files.$(RESET)"

re:			fclean all

.PHONY:		all clean fclean re
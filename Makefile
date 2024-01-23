NAME		=	philo
LIBRARY		=	philo.a

CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra -g
AR			=	ar rcs
RM			=	rm -rf

SRCS		=	philosophers.c

OBJ_DIR		=	obj
OBJS		=	$(SRCS:%.c=$(OBJ_DIR)/%.o)

RAND		=	$(shell shuf -i 100-231 -n 1)
RAND2		=	$(shell shuf -i 100-105 -n 1)

# Function to generate a specific color code between 0 and 231
define COLOR
	\e[$(1)m\e[K\e[1;4;6;38:5:$(2)m
endef

# Function to print a line with the specified color code
define PRINT_COLOR_LINE
	@echo "$(call COLOR,$(1))Color code: $(1)$(RESET)"
endef

#GREEN		=	\e[$(call RAND2)m\e[K\e[1;4;6;38:5:$(call RAND)m
#YELLOW		=	\e[$(call RAND2)m\e[K\e[1;4;6;38:5:$(call RAND)m
#RESET		=	\033[0m

#GREEN		=	\e[0;32m
#YELLOW		=	\e[0;33m
#RESET		=	\033[0m

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

print-colors:
		@for code in $$(seq 0 231); do \
			$(call PRINT_COLOR_LINE,$$code); \
		done

.PHONY:		all clean fclean re
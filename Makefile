NAME		=	philo
LIBRARY		=	philo.a

CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra -g -pthread
AR			=	ar rcs
RM			=	rm -rf

SRCS		=	philosophers.c data_handler.c utils.c \
				malloc_management.c mutex_management.c \
				thread_management.c dinnerparty.c \
				write_status.c variable_handler.c \
				simultaneous.c dinner_watch.c

OBJ_DIR		=	obj
OBJS		=	$(SRCS:%.c=$(OBJ_DIR)/%.o)

GREEN		=	\033[38;5;118m
YELLOW		=	\033[38;5;226m
RESET		=	\033[0m

$(OBJ_DIR)/%.o:	%.c
				@$(CC) $(CFLAGS) -c $< -o $@
				@echo "$(YELLOW)Compiling $<...$(RESET)"

all:		$(NAME)

$(NAME):	$(LIBFT) $(OBJ_DIR) $(OBJS)
			@echo "$(YELLOW)Creating $(LIBRARY) archive...$(RESET)"
			@$(AR) $(LIBRARY) $(OBJS) >/dev/null 2>&1
			@echo "$(YELLOW)Linking $(NAME) executable...$(RESET)"
			@$(CC) $(CFLAGS) -o $(NAME) $(LIBRARY)
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

#for i in {0..255}; do printf "\x1b[38;5;${i}mcolour${i}\x1b[0m\n"; done

#for i in {0..255}; do printf "\x1b[48;5;${i}m colour${i} \x1b[0m\n"; done

#for i in {0..255}; do printf "\x1b[5;38;5;${i}m blinking colour${i} \x1b[0m\n"; done

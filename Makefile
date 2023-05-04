YELLOW			=	\033[1;33m
NC				=	\033[0m
GREEN			=	\033[0;32m
RED				=	\033[0;31m
PURPLE			=	\033[0;35m

NAME			=	minishell
MKDIR			=	mkdir
RM				=	rm -f
CC				=	gcc
FLAGS			=	-Wall -Werror -Wextra 
#-g -fsanitize=address

LIBFTP			=	libraries/libft
PATHB			=	build/
PATHO			=	build/objs/
PATHS			=	src/
PATHSL			=	src/lexer/
PATHSP			=	src/parser/
PATHSB			=	src/builtins/
PATHSEX			=	src/expander/
PATHSU			=	src/utils/
PATHSE			=	src/error/
PATHP			=	src/pipex/
PATHEX			=	src/executor/

BUILD_PATHS 	=	$(PATHB) $(PATHO)

src				=	src/main.c \
					src/lexer/handle_token.c \
					src/lexer/tokenizer.c \
					src/parser/handle_redirections.c \
					src/parser/parser.c \
					src/parser/parser_utils.c \
					src/builtins/builtins.c \
					src/builtins/mini_cd.c \
					src/builtins/mini_echo.c \
					src/builtins/mini_env.c \
					src/builtins/mini_exit.c \
					src/builtins/mini_export.c \
					src/builtins/mini_pwd.c \
					src/builtins/mini_unset.c \
					src/builtins/builtins_utils.c \
					src/utils/signal.c \
					src/utils/minishell_loop.c \
					src/utils/parse_pwd.c \
					src/utils/lexer_clear.c \
					src/utils/lexer_utils.c \
					src/utils/cmds_utils.c \
					src/utils/utils.c \
					src/error/ft_error1.c \
					src/error/ft_error2.c \
					src/executor/check_redirections.c \
					src/executor/executor.c \
					src/executor/handle_cmd.c \
					src/executor/heredoc.c \
					src/executor/executor_utils.c \
					src/expander/expander.c \
					src/expander/expanders_utils.c \
					src/expander/expanders_utils2.c
		

OBJS			=	$(addprefix $(PATHO), $(notdir $(patsubst %.c, %.o, $(src))))

LIBFT			=	./libraries/libft/libft.a

HEADER			=	.includes/builtins.h \
					.includes/error.h \
					.includes/executor.h \
					.includes/lexer.h \
					.includes/minishell.h \
					.includes/parser.h \
					.includes/utils.h 

READLINE_DIR	=	$(shell brew --prefix readline)

READLINE_LIB	= 	-lreadline -lhistory -L $(READLINE_DIR)/lib
	
INCLUDES 		=	-Iincludes -I$(PATHP) -I$(LIBFTP) -I$(READLINE_DIR)/include 

all: $(BUILD_PATHS) $(NAME)

$(PATHO)%.o:: $(PATHS)%.c
	@printf "$(GREEN)██"
	@$(CC) -c $(FLAGS) $(INCLUDES) $< -o $@

$(PATHO)%.o:: $(PATHSL)%.c $(HEADERS)
	@printf "$(GREEN)██"
	@$(CC) -c $(FLAGS) $(INCLUDES) $< -o $@

$(PATHO)%.o:: $(PATHSP)%.c $(HEADERS)
	@printf "$(GREEN)██"
	@$(CC) -c $(FLAGS) $(INCLUDES) $< -o $@

$(PATHO)%.o:: $(PATHSB)%.c $(HEADERS)
	@printf "$(GREEN)██"
	@$(CC) -c $(FLAGS) $(INCLUDES) $< -o $@

$(PATHO)%.o:: $(PATHSEX)%.c $(HEADERS)
	@printf "$(GREEN)██"
	@$(CC) -c $(FLAGS) $(INCLUDES) $< -o $@

$(PATHO)%.o:: $(PATHSU)%.c $(HEADERS)
	@printf "$(GREEN)██"
	@$(CC) -c $(FLAGS) $(INCLUDES) $< -o $@

$(PATHO)%.o:: $(PATHSE)%.c $(HEADERS)
	@printf "$(GREEN)██"
	@$(CC) -c $(FLAGS) $(INCLUDES) $< -o $@

$(PATHO)%.o:: $(PATHEX)%.c $(dHEADERS)
	@printf "$(GREEN)██"
	@$(CC) -c $(FLAGS) $(INCLUDES) $< -o $@

$(NAME): $(LIBFT) $(OBJS) $(HEADERS)
	@$(CC) $(FLAGS) $(LIBFT) $(OBJS) $(READLINE_LIB) -o $(NAME)
	@echo "\n⭐️ ${YELLOW}$(NAME) created ⭐️${NC}"

$(LIBFT):
	@$(MAKE) -C ./libraries/libft

$(PATHB):
	@$(MKDIR) $(PATHB)

$(PATHO):
	@$(MKDIR) $(PATHO)

clean:
	@$(RM) $(OBJS)
	@$(RM) $(PATHB).tmp*
	@rmdir $(PATHO) $(PATHB)
	@make fclean -C libraries/libft
	@echo "👾 ${PURPLE} object files deleted  👾${NC}"

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(LIBFT)
	@echo "👾 ${PURPLE} all files deleted  👾${NC}"	


re:
	@make fclean 
	@make all

.PRECIOUS	: $(PATHO)%.o
.PHONY		:	all clean fclean re
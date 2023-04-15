SRCS =  ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isprint.c\
		ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c\
		ft_strrchr.c ft_strncmp.c ft_strnstr.c ft_strdup.c\
		ft_memset.c ft_memcpy.c ft_memmove.c ft_memchr.c ft_memcmp.c\
		ft_bzero.c ft_toupper.c ft_tolower.c ft_atoi.c ft_calloc.c\
		ft_substr.c ft_strjoin.c ft_strtrim.c ft_itoa.c\
		ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c\
		ft_putendl_fd.c ft_putnbr_fd.c ft_isascii.c ft_split.c

BNS_SRCS = ft_lstsize.c ft_lstadd_back.c ft_lstadd_front.c \
		   ft_lstclear.c ft_lstdelone.c ft_lstiter.c \
		   ft_lstlast.c ft_lstmap.c ft_lstnew.c

OBJS = $(SRCS:.c=.o)
BNS_OBJS = $(BNS_SRCS:.c=.o)

CC = cc
FLAGS = -Wall -Wextra -Werror
NAME = libft.a
RM = rm -f
AR = ar -rcs
INCLUDES = libft.h

all	:	$(NAME)

$(NAME)	:	$(OBJS)
		$(AR) $(NAME) $(OBJS)
bonus :		$(OBJS) $(BNS_OBJS)
		@make OBJS="$(OBJS) ${BNS_OBJS}"
		
%.o : %.c $(INCLUDES)
	$(CC) $(FLAGS) -c $< -o $@

clean	:
		$(RM) $(OBJS) $(BNS_OBJS)

fclean	:	clean
		$(RM) $(NAME)

re	:	
	make fclean 
	make all

.PHONY	:	all clean fclean re bonus

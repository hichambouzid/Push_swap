NAME = libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c  ft_tolower.c \
		ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memset.c ft_bzero.c ft_memchr.c ft_memcpy.c ft_memmove.c \
		ft_toupper.c ft_memcmp.c ft_strlcpy.c ft_strlcat.c ft_atoi.c ft_strnstr.c ft_strdup.c ft_calloc.c \
		ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

OBJS=$(SRCS:.c=.o)

NAME_BNS = .v

SRCS_BNS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c \
	ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c

OBJS_BNS = ft_lstnew_bonus.o ft_lstadd_front_bonus.o ft_lstsize_bonus.o ft_lstlast_bonus.o ft_lstadd_back_bonus.o \
	ft_lstdelone_bonus.o ft_lstclear_bonus.o ft_lstiter_bonus.o

all: $(NAME)

$(NAME): $(OBJS)
	ar -rc $(NAME) $(OBJS)

bonus : $(NAME) $(NAME_BNS)

$(OBJS_BNS) : $(SRCS_BNS)
	$(CC) $(CFLAGS) -c $(SRCS_BNS)

$(NAME_BNS) : $(OBJS_BNS)
	ar -rc $(NAME) $(OBJS_BNS)
	@touch $(NAME_BNS)

clean:
	rm -rf $(OBJS) $(OBJS_BNS)
	@rm -rf $(NAME_BNS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

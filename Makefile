CFLAGS := -Wall -Wextra -Werror

SRCS := ft_isalpha.c ft_isdigit.c \
		ft_isalnum.c ft_isascii.c \
		ft_isprint.c ft_strlen.c \
		ft_memset.c ft_bzero.c \
		ft_memcpy.c ft_memmove.c \
		ft_strlcpy.c ft_strlcat.c \
		ft_toupper.c ft_tolower.c \
		ft_strchr.c ft_strrchr.c \
		ft_strncmp.c ft_memchr.c \
		ft_memcmp.c ft_strnstr.c \
		ft_atoi.c ft_calloc.c \
		ft_strdup.c ft_substr.c \
		ft_strjoin.c ft_strtrim.c \
		ft_split.c

OBJS := $(SRCS:.c=.o)

NAME := libft.a

.PHONY := clean fclean re $(NAME) all

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $?

$(OBJS): %.o: %.c
	cc $(CFLAGS) -c $< -o $@ -I/.

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

debug: re
	cc $(CFLAGS) main.c $(NAME)
	clear
	./a.out
	@make fclean
	@rm a.out

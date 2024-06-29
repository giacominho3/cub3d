NAME = libft.a

COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;31m
COLOUR_BLUE=\033[0;34m
COLOUR_END=\033[0m

SRCS		= ft_atoi.c \
			ft_isalnum.c \
			ft_isdigit.c \
			ft_strchr.c \
			ft_strlcpy.c \
			ft_strnstr.c \
			ft_toupper.c \
			ft_bzero.c \
			ft_isalpha.c \
			ft_isprint.c \
			ft_strdup.c \
			ft_strlen.c \
			ft_strrchr.c \
			ft_calloc.c \
			ft_isascii.c \
			ft_memset.c \
			ft_strlcat.c \
			ft_strncmp.c \
			ft_tolower.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_putchar_fd.c\
			ft_putendl_fd.c\
			ft_putstr_fd.c\
			ft_putnbr_fd.c\
			ft_strmapi.c\
			ft_striteri.c\
			ft_itoa.c\
			ft_strtrim.c\
			ft_split.c

BONUS		=	ft_lstadd_back.c \
				ft_lstadd_front.c \
				ft_lstlast.c \
				ft_lstnew.c \
				ft_lstsize.c \
				ft_lstdelone.c\
				ft_lstclear.c\
				ft_lstiter.c\
				ft_lstmap.c

OBJS = ${SRCS:.c=.o}

OBJSBONUS = ${BONUS:.c=.o}

CC		= gcc
RM		= rm -f

CFLAGS = -Wall -Wextra -Werror

.c.o:
	@${CC} ${CFLAGS} -g -c $< -o ${<:.c=.o}

$(NAME): ${OBJS} ${OBJSBONUS}
	@ar rcs ${NAME} ${OBJS} ${OBJSBONUS}

bonus:	${OBJSBONUS}
	@ar rcs ${NAME} ${OBJSBONUS}


all:	${NAME}

clean:
	@${RM} ${OBJS} ${OBJSBONUS}

fclean:	clean
	@${RM} ${NAME}

re:		fclean all

.PHONY: all bonus clean fclean re

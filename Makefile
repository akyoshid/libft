# Archive file(.a) is a library file \
# that consolidates multiple object files into one.
# It makes the linking process more efficient.
NAME = libft.a

SRCS = \
	ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_strlen.c \
	ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strncmp.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strnstr.c \
	ft_atoi.c \
	ft_calloc.c \
	ft_strdup.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_split.c \
	ft_itoa.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c

BONUS_SRCS = \
	ft_lstnew.c \
	ft_lstadd_front.c \
	ft_lstsize.c \
	ft_lstlast.c \
	ft_lstadd_back.c \
	ft_lstdelone.c \
	ft_lstclear.c \
	ft_lstiter.c \
	ft_lstmap.c

# An object file is a file \
# that has been translated from source code to machine language by a compiler.
# Each source file is compiled into its own individual object file.
# By using (saving) object files, \
# it is possible to shorten the build time for the second and subsequent builds, \
# as only the source files that have been changed need to be recompiled.
# ---
# `:`: Indicates the start of a pattern substitution
# `=`: Separates the pattern to be replaced from the new pattern
OBJS = ${SRCS:.c=.o}

BONUS_OBJS  = $(BONUS_SRCS:.c=.o)

ifdef WITH_BONUS
OBJS += ${BONUS_OBJS}
endif

CC = cc

CFLAGS = -Wall -Wextra -Werror

# If the file you are trying to delete does not exist, \
# an error message is usually displayed, \
# but using the -f option suppresses these messages.
RM = rm -f

all: $(NAME)

# Prefixing a command with '@' \
# suppresses the output of the command itself when executed.
bonus:
	@make $(NAME) WITH_BONUS=1

# ar: Create an archive file (cannot update)
# -r: Update the archive file if one with the specified name exists, \
#     otherwise create a new one
# -c: Do not output messages when creating an archive
# -s: Create a symbol table in the archive
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

# "Pattern Rule is a rule common to multiple targets that match a specific pattern.
# `%`: Used in pattern rules, it matches any string of characters.
# `-c`: Compiles without linking.
# `$<`: Refers to the first item in the dependency list.
# `-o`: Specifies the name of the output file.
# `$@`: Refers to the name of the target file."
%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(RM) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus

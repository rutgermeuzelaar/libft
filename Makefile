CC = cc
CFLAGS = -g -Wall -Wextra -Werror
BUILDDIR = build
OBJDIR = build/src
SRCDIR = src/src
SOURCE = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c  \
ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c \
ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c \
ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c \
ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
OBJECTS = $(SOURCE:%.c=$(OBJDIR)/%.o)
NAME = libft.a

OBJDIR_BONUS = build/bonus
SRCDIR_BONUS = src/bonus
SOURCE_BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c ft_lstadd_back.c
OBJECTS_BONUS = $(SOURCE_BONUS:%.c=$(OBJDIR_BONUS)/%.o)

.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(OBJECTS)
	ar -rcs $(NAME) $(OBJECTS)

$(OBJECTS): $(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJDIR): | $(BUILDDIR)
	mkdir $(OBJDIR)

$(BUILDDIR):
	mkdir $(BUILDDIR)

$(OBJECTS_BONUS): $(OBJDIR_BONUS)/%.o: $(SRCDIR_BONUS)/%.c | $(OBJDIR_BONUS)
	$(CC) $(CFLAGS) -c -o $@ $<
	ar -rs $(NAME) $@

$(OBJDIR_BONUS): | $(BUILDDIR)
	mkdir $(OBJDIR_BONUS)

bonus: $(NAME) $(OBJECTS_BONUS)

re: fclean all

clean:
	rm -f $(OBJECTS)
	rm -f $(OBJECTS_BONUS)

fclean: clean
	rm -f $(NAME)
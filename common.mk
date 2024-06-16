CC = cc
CFLAGS = -Wall -Wextra -Werror -g
SRCDIR = src
OBJDIR = build
OBJECTS_STANDARD = $(SOURCES_STANDARD:%.c=$(OBJDIR)/%.o)
OBJECTS_SHARED = $(SOURCES_SHARED:%.c=$(OBJDIR)/%.o)
OBJECTS_BONUS = $(SOURCES_BONUS:%.c=$(OBJDIR)/%.o)
OBJECTS = $(OBJECTS_STANDARD) $(OBJECTS_SHARED) $(OBJECTS_BONUS)
NAME = $(OBJECTS_SHARED) $(OBJECTS_STANDARD)

.PHONY: all clean fclean re

all: $(NAME)

$(OBJDIR):
	mkdir $(OBJDIR)

$(OBJECTS_STANDARD): $(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJECTS_SHARED): $(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJECTS_BONUS): $(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c -o $@ $<

bonus: $(OBJECTS_SHARED) $(OBJECTS_BONUS)

clean:
	rm -r -f $(OBJECTS)

fclean: clean

re: fclean all



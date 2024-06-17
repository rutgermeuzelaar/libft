CC := cc
CFLAGS := -Wall -Wextra -Werror -g -c -o
SRCDIR := src
OBJDIR := build
OBJECTS_STANDARD := $(SOURCES_STANDARD:%.c=$(OBJDIR)/%.o)
OBJECTS_SHARED := $(SOURCES_SHARED:%.c=$(OBJDIR)/%.o)
OBJECTS_BONUS := $(SOURCES_BONUS:%.c=$(OBJDIR)/%.o)
SHARED_DEFINITION := false
OUTDATED_ARCHIVE := $(shell entry_in_archive.sh)
NAME := ../../libft.a

.PHONY: all

all: $(NAME)

cheese:
	ar -rcs $(NAME) $(OBJECTS_STANDARD) $(OBJECTS_SHARED)

tell:
ifeq ($(SHARED_DEFINITION), true)
	echo "Geinige hond"
else
	echo "rot kat"
endif

bonus: $(NAME) $(OBJECTS_BONUS)
ifeq ($(SHARED_DEFINITION), true)
	ar -d $(NAME) $(OBJECTS_STANDARD)
endif

$(OBJECTS_BONUS): $(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) $@ $<
	ar -rs $(NAME) $@

$(OBJDIR):
	mkdir $(OBJDIR)

$(OBJECTS_STANDARD) $(OBJECTS_SHARED): $(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) $@ $<

$(NAME): $(OBJECTS_STANDARD) $(OBJECTS_SHARED)
	ar -rcs $(NAME) $(OBJECTS_STANDARD) $(OBJECTS_SHARED)

clean:
	rm -rf $(OBJECTS_STANDARD) $(OBJECTS_SHARED) $(OBJECTS_BONUS)
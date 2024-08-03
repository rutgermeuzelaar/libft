CC := cc
INC_DIRS := ../../include
INC := $(foreach dir, $(INC_DIRS), -I$(dir))
CFLAGS := -Wall -Wextra -Werror $(INC) -g -c -o
SRCDIR := src
OBJDIR := build
OBJECTS_STANDARD := $(SOURCES_STANDARD:%.c=$(OBJDIR)/%.o)
OBJECTS_SHARED := $(SOURCES_SHARED:%.c=$(OBJDIR)/%.o)
OBJECTS_BONUS := $(SOURCES_BONUS:%.c=$(OBJDIR)/%.o)
SHARED_DEFINITION := false
NAME := ../../libft.a

.PHONY: all

all: $(NAME)

bonus: $(NAME) $(OBJECTS_BONUS)
ifeq ($(SHARED_DEFINITION), true)
ifeq ($(shell ../../entry_in_archive.sh $(notdir $(OBJECTS_STANDARD))), 1)
	ar -d $(NAME) $(OBJECTS_STANDARD)
endif
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
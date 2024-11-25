SHELL := /bin/bash
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

$(NAME)(%.o): %.o
	ar -csrU $(NAME) $<

$(NAME): $(NAME)($(OBJECTS_STANDARD) $(OBJECTS_SHARED))
	ar -s $(NAME)

$(OBJDIR):
	mkdir $(OBJDIR)

$(OBJECTS_STANDARD) $(OBJECTS_SHARED) $(OBJECTS_BONUS): \
$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) $@ $<

bonus: $(NAME)($(OBJECTS_BONUS)) remove-standard

remove-standard:
	@for stdobj in $(OBJECTS_STANDARD); do \
		if ar -t $(NAME) | grep -q "$$(basename $$stdobj)"; then \
			ar -d $(NAME) $$stdobj; \
		fi; \
	done

clean:
	rm -rf $(OBJECTS_STANDARD) $(OBJECTS_SHARED) $(OBJECTS_BONUS)

re: clean all

APPS := $(shell find ./apps -maxdepth 1 -mindepth 1 -type d -print)
APP_OBJDIR := /build
APP_OBJDIR_ALL := $(addsuffix $(APP_OBJDIR), $(APPS))
NAME := libft.a

.PHONY: all clean fclean re bonus tell

all: lib

tell:
	$(foreach app, $(APPS), $(MAKE) tell -C $(app);)

lib:
	$(foreach app, $(APPS), $(MAKE) -C $(app);)

bonus:
	$(foreach app, $(APPS), $(MAKE) bonus -C $(app);)

clean:
	$(foreach app, $(APPS), $(MAKE) clean -C $(app);)

fclean: clean
	rm -rf $(NAME)

re: fclean all

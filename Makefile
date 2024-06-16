ROOT_DIR = ./
# APPS := $(shell find ./apps -maxdepth 1 -mindepth 1 -type d -print)
APPS := ./apps/ft_printf ./apps/get_next_line ./apps/libft
SOURCES := 
NAME = libft.a

.PHONY: all clean fclean re bonus 

all: $(NAME)

$(NAME):
	$(foreach app, $(APPS), $(MAKE) -C $(app);)
	ar -rcs $(NAME) $(foreach app, $(APPS), $(wildcard $(app)/build/*.o))

bonus: $(NAME)

clean:
	$(foreach app, $(APPS), $(MAKE) clean -C $(app);)

fclean:
	rm -rf $(NAME)
	$(foreach app, $(APPS), $(MAKE) fclean -C $(app);)

re: fclean all
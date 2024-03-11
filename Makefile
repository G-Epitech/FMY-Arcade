##
## EPITECH PROJECT, 2024
## arcade
## File description:
## Makefile
##

NAME = 				arcade
BUILD_PATH = 	build

all:
					@cmake -S . -B build
					cmake --build $(BUILD_PATH)
					@cp $(BUILD_PATH)/src/$(NAME) .

clean:
					@make -C $(BUILD_PATH) clean

fclean:
					@rm -f $(NAME)
					@rm -rf $(BUILD_PATH)

re: 			fclean all

tests_run:
					echo "pass"

.PHONY: all clean fclean re tests_run
DEFAULT_GOAL := all

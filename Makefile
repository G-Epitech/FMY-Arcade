##
## EPITECH PROJECT, 2024
## arcade
## File description:
## Makefile
##

NAME = 				arcade
BUILD_PATH = 		build

all:			update
					@cmake -S . -B build
					cmake --build $(BUILD_PATH)

clean:
					@rm -rf $(BUILD_PATH)

fclean:		clean
					@rm -f $(NAME)

re: 			fclean all

tests_run:
					echo "pass"

update:
					@git submodule init
					@git submodule update

.PHONY: all clean fclean re tests_run update
DEFAULT_GOAL := all

##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## iojvd
##

SRC_DIR = src
LIB_DIR = lib/my

SRC = $(wildcard $(SRC_DIR)/*.c)
LIB = $(wildcard $(LIB_DIR)/*.c)

OBJ = $(SRC:.c=.o) $(LIB:.c=.o)

all: $(OBJ)
	@(gcc $(OBJ) -o mysh -g -I../includes -lm)

clean:
	@(rm -f *.o)
	@(cd src && rm -f *.o)
	@(cd lib/my && rm -f *.o)

fclean: clean
	@(rm -f $(NAME))

re: fclean all
	@(make clean)

coding_style: clean
	cd ../coding-style-checker/ \
	&& ./coding-style.sh ../B-PSU-200-MAR-2-1-minishell1-hatim.ouaadi/ \
	&& cd ../B-PSU-200-MAR-2-1-minishell1-hatim.ouaadi/ \
	&& make \
	&& clear \
	&& cd ../coding-style-checker/ \
	&& cat coding-style-reports.log

valgrind: fclean
	@(gcc $(SRC) -g3 -o mysh -I../includes -lm)

push:
	@(find . -type f -name "#.#" -delete -o -name "*~" -delete)
	@(rm mysh)
	@(git add .)
	@(git commit -m "Final push")
	@(git push)

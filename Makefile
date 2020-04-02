NAME = sudoku

SRC = *.c

all:
	gcc -Wall -Wextra -Werror -o $(NAME) $(SRC)

clean:
	/bin/rm -f $(NAME)

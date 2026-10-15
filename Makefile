##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## make
##

SRC =	lib/my/my_insert.c\
        lib/my/my_len.c\
        lib/my/my_line.c\
        lib/my/my_occ.c\
        lib/my/my_parse.c\
        lib/my/my_put.c\
        lib/my/my_sort.c\
        lib/my/my_str.c\
        lib/my/my_strn.c\
        lib/my/my_tab.c\
        lib/my/my_tools.c\
        lib/my/my_type.c\
	src/make_order.c\
	src/algo.c\
	src/print.c\
	src/get_tunnels.c\
        src/get_room_pos.c\
        src/init_room.c\
        src/make_link.c\
        src/queue.c\
        src/weight_rooms.c\
        src/print_moves.c\
        src/check_ant.c\
        src/check_room.c\
        src/check_tunnel.c\
        src/my_str_to_word_array.c\
	$(BINARY).c\

OBJ =	$(SRC:.c=.o)

DEBUG = -Wall -Wextra -g3

NAME =	libmy.a

BINARY = lem_in

all:	$(NAME)

$(NAME):$(OBJ)
	ar rc $(NAME) $(OBJ)
	gcc -o $(BINARY) $(BINARY).c -L. -lmy

debug:	$(OBJ)
	ar rc $(NAME) $(OBJ)
	gcc -o $(BINARY) $(BINARY).c $(DEBUG) -L. -lmy

clean:
	rm -f $(OBJ)
	find . -name "*.o" -delete
	find . -name "*~" -delete
	find . -name "#*#" -delete
	find . -name "vgcore.*" -delete

fclean:	clean
	rm -f $(NAME)
	rm -f $(BINARY)

re:	fclean all

.PHONY:	clean fclean re all

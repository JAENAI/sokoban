CFLAGS = -Wall -Wextra
LDFLAGS = -o
CC = gcc

main : main.o grid.o player.o
	$(CC)$(CFLAGS)$(LDFLAGS) $@ $^ 
main.o : main.c grid.h player.h
	$(CC)$(CFLAGS) -c $<
player.o : player.c player.h grid.h
	$(CC)$(CFLAGS) -c $<
grid.o : grid.c grid.h
	$(CC)$(CFLAGS) -c $<
clean : 
	rm -f *.o
doc :
	doxygen -g
	PROJECT_NAME ="projet-sokoban"
	INPUT= .
	doxygen Doxyfile
archive :
	tar -cf RUGENGANDE_IHIMBAZWE_Jaenai.tar.gz 'projet-sokoban'

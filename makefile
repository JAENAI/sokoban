CFLAGS = -Wall -Wextra
LDFLAGS = -o
CC = gcc

main : main.o grid.o grid.h player.h
	$(CC) $(CFLAGS) $(LDFLAGS) $@ main.c grid.c player.c
main.o : main.c grid.h player.h
	$(CC) $(CFLAGS) -c $<
grid.o: grid.c grid.h player.h
	$(CC) $(CFLAGS) -c $<
clean : 
	rm -f *.o
doc :
	doxygen -g
	PROJECT_NAME ="projet_sokoban"
	INPUT= .
	doxygen Doxyfile
archive :
	tar -cf RUGENGANDE_IHIMBAZWE_Jaenai.tar.gz 'projet-sokoban'


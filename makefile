CFLAGS = -Wall -Wextra
CC = gcc -g

main : main.o grid.o player.o grid.h player.h
	$(CC) $(CFLAGS) -o $@ main.c grid.c player.c
main.o : main.c grid.h player.h
	$(CC) $(CFLAGS) -c $<
grid.o: grid.c grid.h player.h
	$(CC) $(CFLAGS) -c $<
player.o: player.c grid.h player.h
	$(CC) $(CFLAGS) -c $<
clean : 
	rm -f *.o
	rm -f main.exe
	rm -f RUGENGANDE_IHIMBAZWE_Jaenai.tar.gz
doc :
	doxygen Doxyfile
archive :
	tar -cf RUGENGANDE_IHIMBAZWE_Jaenai.tar.gz *.c *.h makefile level1.txt


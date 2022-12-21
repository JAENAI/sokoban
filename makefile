CFLAGS = -Wall -Wextra
CC = gcc -g
INCLUDE= -I install_dir/include
LDFLAGS=-lm -lSDL2 -Linstall_dir/lib

main : main.o grid.o player.o sdl2.o grid.h player.h sdl2.h
	$(CC) $(CFLAGS) -o $@ main.o grid.o player.o sdl2.o $(LDFLAGS) 
main.o: main.c grid.h player.h sdl2.h
	$(CC) $(CFLAGS) -c $(INCLUDE) $<
player.o: player.c grid.h player.h
	$(CC) $(CFLAGS) -c $<
grid.o: grid.c grid.h player.h
	$(CC) $(CFLAGS) -c $<
sdl2.o: sdl2.c sdl2.h grid.h
	$(CC) $(CFLAGS) $(INCLUDE) -c $<
config:
	cd SDL2 && chmod 777 configure
	cd SDL2 && ./configure --prefix=$(PWD)/install_dir
	cd SDL2 && make install -j6
clean : 
	rm -rf *.o main  RUGENGANDE_IHIMBAZWE_Jaenai.tar.gz install_dir
doc :
	doxygen Doxyfile
archive :
	tar -cf RUGENGANDE_IHIMBAZWE_Jaenai.tar.gz *.c *.h makefile level1.txt Doxyfile README.md SDL2
sdl2 :
	./main --sdl2
console:
	./main --console
console1:
	./main

main : main.o grid.o
gcc -o $@ $^ 
%.o : %.c
gcc -c $<
clean: rm -f *.o

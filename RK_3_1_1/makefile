CC := gcc
CFLAGS := -std=c99 -Wall -Werror -pedantic
OBJ := main.o funcs.o

app.exe : $(OBJ)
	$(CC) -o $@ $^

main.o : main.c
	$(CC) $(CFLAGS) -c -o $@ $<

funcs.o : funcs.c funcs.h
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY : clean
clean :
	rm -r *.o *.exe

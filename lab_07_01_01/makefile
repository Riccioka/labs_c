CFLAGS := -std=c99 -Wall -Werror -pedantic

app.exe : out/main.o out/funcs.o out/print_in_file.o out/key.o out/mysort.o
	gcc -o app.exe out/main.o out/funcs.o out/print_in_file.o out/key.o out/mysort.o

unit_tests.exe : out/main_check.o out/key.o out/mysort.o
	gcc -o unit_tests.exe out/main_check.o out/key.o out/mysort.o

out/main.o : src/main.c
	gcc $(CFLAGS) -c -o out/main.o src/main.c

out/funcs.o : src/funcs.c inc/funcs.h
	gcc $(CFLAGS) -c -o out/funcs.o src/funcs.c

out/print_in_file.o : src/print_in_file.c inc/print_in_file.h
	gcc $(CFLAGS) -c -o out/print_in_file.o src/print_in_file.c

out/key.o : src/key.c inc/key.h
	gcc $(CFLAGS) -c -o out/key.o src/key.c

out/mysort.o : src/mysort.c inc/mysort.h
	gcc $(CFLAGS) -c -o out/mysort.o src/mysort.c

out/main_check.o : unit_tests/main_check.c
	gcc $(CFLAGS) -c -o out/main_check.o unit_tests/main_check.c

.PHONY : clean
clean :
	$(RM) out/*.o *.exe

CFLAGS := -std=c99 -Wall -Werror -Wpedantic -Iinc

app.exe : out/main.o out/find.o out/use_funcs.o out/product.o out/arr_product.o
	gcc -o app.exe out/main.o out/find.o out/use_funcs.o out/product.o out/arr_product.o -lm

unit_tests.exe : out/check_main.o out/find.o out/use_funcs.o out/product.o out/check_use_funcs.o out/check_find.o
	gcc -o unit_tests.exe out/check_main.o out/find.o out/use_funcs.o out/product.o out/check_use_funcs.o out/check_find.o -lcheck

out/main.o : src/main.c inc/find.h inc/product.h inc/use_funcs.h
	gcc $(CFLAGS) -c -o out/main.o src/main.c

out/find.o : src/find.c inc/find.h inc/product.h
	gcc $(CFLAGS) -c -o out/find.o src/find.c

out/use_funcs.o : src/use_funcs.c inc/use_funcs.h
	gcc $(CFLAGS) -c -o out/use_funcs.o src/use_funcs.c

out/product.o : src/product.c inc/product.h
	gcc $(CFLAGS) -c -o out/product.o src/product.c

out/arr_product.o : src/arr_product.c inc/arr_product.h
	gcc $(CFLAGS) -c -o out/arr_product.o src/arr_product.c

out/check_main.o : unit_tests/check_main.c inc/check_main.h
	gcc $(CFLAGS) -c -o out/check_main.o unit_tests/check_main.c

out/check_find.o : unit_tests/check_find.c inc/check_main.h
	gcc $(CFLAGS) -c -o out/check_find.o unit_tests/check_find.c

out/check_use_funcs.o : unit_tests/check_use_funcs.c inc/check_main.h
	gcc $(CFLAGS) -c -o out/check_use_funcs.o unit_tests/check_use_funcs.c

.PHONY : clean
clean :
	$(RM) out/*.o *.exe

unit : unit_tests.exe
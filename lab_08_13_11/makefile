CC = gcc
SRC_DIR := ./src
INC_DIR := ./inc
OUT_DIR := ./out

FTESTS_DIR := ./func_tests
UTESTS_DIR := ./unit_tests

CFLAGS =-std=c99 -Wall -Werror -Wpedantic -ggdb -I$(INC_DIR)
LFLAGS =--coverage
.PHONY : clean dir func

func: CFLAGS+= --coverage
func: LFLAGS+= -g3

OBJECTS_READ := $(OUT_DIR)/memory_matrix.o $(OUT_DIR)/checks.o $(OUT_DIR)/funcs_matrix.o
OBJECTS_OPERATIONS := $(OUT_DIR)/actions.o $(OUT_DIR)/funcs_matrix.o
OBJECTS_MAIN := $(OUT_DIR)/main.o
OBJECTS_UNIT := $(OUT_DIR)/check_main.o $(OUT_DIR)/check_memory.o

app.exe: $(OBJECTS_MAIN) $(OBJECTS_READ) $(OUT_DIR)/actions.o
	$(CC) $(LFLAGS) -ggdb -o $@ $^

unit_tests.exe: out/memory_matrix.o out/check_main.o out/checks.o out/check_memory.o out/check_actions.o out/funcs_matrix.o out/actions.o
	gcc -o unit_tests.exe out/memory_matrix.o out/checks.o out/check_main.o out/check_actions.o out/check_memory.o out/funcs_matrix.o out/actions.o -lcheck

$(OUT_DIR)/check_%.o: $(UTESTS_DIR)/check_%.c | dir
	$(CC) $(CFLAGS) -c $< -o $@

$(OUT_DIR)/%.o: $(SRC_DIR)/%.c | dir
	$(CC) $(CFLAGS) -c $^ -o $@

$(OUT_DIR)/release.lastbuildstate: | dir
	rm -rf *.exe $(OUT_DIR)/*.o $(OUT_DIR)/debug.lastbuildstate
	touch $(OUT_DIR)/release.lastbuildstate

$(OUT_DIR)/debug.lastbuildstate: | dir
	rm -rf *.exe $(OUT_DIR)/*.o $(OUT_DIR)/release.lastbuildstate
	touch $(OUT_DIR)/debug.lastbuildstate

dir:
	mkdir -p $(OUT_DIR)/

unit:	unit_tests.exe
	./unit_tests.exe

func:
	cd $(FTESTS_DIR) && bash all_tests.sh

clean:
	rm -fv *.exe
	rm -fv $(OUT_DIR)/*.o
	rm -fv $(OUT_DIR)/*.gcno
	rm -fv $(OUT_DIR)/*.gcda
	rm -rf $(OUT_DIR)/*.lastbuildstate
	rm -rf $(OUT_DIR)

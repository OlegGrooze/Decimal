#Git
USER_1=barbreye
BRANCH=develop
#Compile
GCC=gcc
GCC_C=gcc -c
GCC_G=gcc -g
FLAGS= -Wall -Werror -Wextra -std=c11 -g
UBUNTU_FLAGS=
TESTS= -pthread -lcheck_pic -pthread -lrt -lm -lsubunit
TESTS_IOS= -lcheck
#Files
SOURCE_LIB_C= fun/arithmetic/*.c fun/comparison/*.c fun/converters/*.c fun/over/*.c
SOURCE_COMMON_C=  common/fun/*.c common/checks/*.c common/binary/*.c common/norm/*.c common/read/*.c common/round/*.c

SOURCE_LIB_O= *.o
SOURCE_LIB_A= *.a
SOURCE_LIB_H= s21_decimal.h common/s21_add_functions.h

SOURCE_TEST_H=tests/test_s21_decimal.h
SOURCE_TEST_C=tests/run_tests.c tests/all/*.c
ALL_FILES= ${SOURCE_LIB_C} ${SOURCE_LIB_H} ${SOURCE_TEST_C} ${SOURCE_TEST_H} ${SOURCE_COMMON_C}
SOURCE_TESTS= -o run_tests
#Tests
GCOV= -lcheck -lgcov -fprofile-arcs --coverage
VALGRIND_IOS=

#========================================
UNAME:=$(shell uname -s)
ifeq ($(UNAME),Linux)
	LDFLAGS=-lcheck_pic -lsubunit -lm -lrt -lpthread
	OPEN_CM=xdg-open
endif
ifeq ($(UNAME),Darwin)
	LDFLAGS=-lcheck -lm
	OPEN_CM=open
endif
#========================================
#================== ALL ===========================
all: clean s21_decimal.a

#================== BUILD =========================
s21_decimal.a: clean
	${GCC_C} -g ${SOURCE_LIB_C} ${SOURCE_COMMON_C}
	ar rc s21_decimal.a *.o
	ranlib s21_decimal.a
	make clean.o
#================== CLEAN =========================
clean:
	rm -rf *.o
	rm -rf *.a
	rm -rf run_*
	rm -rf *.gcno
	rm -rf *.gcda
	rm -rf ./tests/*.a
	rm -rf report
clean.a:
	rm -rf *.a tests/*.a
clean.o:
	rm -rf *.o
#================== STYLE =========================
style:
	clang-format -n ${ALL_FILES}
style_red:
	clang-format -i ${ALL_FILES}
#================== TESTS =========================
test: clean s21_decimal.a test.a
	gcc ${FLAGS} tests/run_tests.c tests/test_s21_decimal.a s21_decimal.a -o run_tests ${LDFLAGS}
test2: clean s21_decimal.a test.a
	gcc ${FLAGS} tests/run_tests.c tests/all/*.c s21_decimal.a -o run_tests ${LDFLAGS}
test.a:
	${GCC_C} ${FLAGS} tests/all/*.c
	ar rc tests/test_s21_decimal.a *.o
	ranlib tests/test_s21_decimal.a
	make clean.o
#================== VALGRIND ======================
valgrind:
	valgrind --leak-check=full --track-origins=yes ./run_tests
tests_val: clean test
	valgrind --leak-check=full --track-origins=yes ./run_tests

#--log-file=res_leak.txt
tests_val_gcov: clean gcov_report
	valgrind --leak-check=full --track-origins=yes ./run_gcov
	rm -rf *.gcda
#================== GIT ===========================
git: clean style_red
	git add .
	git commit -m "${USER_1} ---> developing... "
	git push origin ${BRANCH}
#================== GCOV ==========================
gcov_report: clean
	${GCC_C} -g tests/all/*.c -fprofile-arcs -ftest-coverage
	ar rc tests/test_s21_decimal.a *.o
	ranlib tests/test_s21_decimal.a
	make clean.o

	${GCC_C} -g ${SOURCE_LIB_C} ${SOURCE_COMMON_C} -fprofile-arcs -ftest-coverage
	ar rc s21_decimal.a *.o
	ranlib s21_decimal.a
	make clean.o

	gcc tests/run_tests.c tests/test_s21_decimal.a s21_decimal.a ${LDFLAGS} -fprofile-arcs -ftest-coverage -o run_gcov
	./run_gcov
	lcov -t gcov_report -o gcov_report.info -c -d ./
	rm -rf report
	mkdir report
	genhtml -o report gcov_report.info;
	rm -rf *.gcda *.gcno
	rm -rf *.o *.info
html:
	open report/index.html

#==================================================

# Скрипты для быстрых проверок
install_script_ios:
	brew install gcov -y
	brew install gcc -y
	brew install check -y
install_script_ubuntu:
	sudo apt install make
	sudo apt install git
	sudo apt install gcc -y
	sudo apt install check -y

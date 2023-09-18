CXX = g++
CPP_STD:=-std=c++17
TARGET:=SmartCallc2.0
CXXFLAGS = -g -lstdc++ -Wall -Wextra --coverage #-Werror
BUILD_DIR := build
SRC_DIRS := src
SRCS := $(shell find $(SRC_DIRS) -maxdepth 1 -name *.cc)
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
GT_SRCS := $(shell find $(SRC_DIRS) -maxdepth 1 -name *.cc)
GT_OBJS := $(GT_SRCS:%=$(BUILD_DIR)/%.o)
GT_FLAGS = -lgtest

OS := $(shell uname -s)

all: t

#  Google tests
test: $(GT_OBJS)
	$(CXX) $(CXXFLAGS) $(GT_OBJS) -o $(BUILD_DIR)/$(TARGET) $(GT_FLAGS)
	./$(BUILD_DIR)/$(TARGET)

# Build step for C++ source
$(BUILD_DIR)/%.cc.o: %.cc
	mkdir -p $(dir $@)
	$(CXX) $(CPP_STD) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)/* test.info report test.log

clang:
	# cp -R materials/linters/.clang-format ./
	clang-format -style=file:materials/linters/.clang-format -n src/*.h src/google_tests/*.cc
	clang-format -style=file:materials/linters/.clang-format -i src/*.h src/google_tests/*.cc

start:
	./$(BUILD_DIR)/$(TARGET)

valgrind:
ifeq ($(OS), Darwin)
	echo $(OS)
	echo "For Aple --------------------"
	leaks -atExit -- ./$(BUILD_DIR)/$(TARGET)
else
	echo $(OS)
	echo "For Ubuntu --------------------"
	CK_FORK=no valgrind --vgdb=no --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=RESULT_VALGRIND.txt $(BUILD_DIR)/$(TARGET)
	grep errors RESULT_VALGRIND.txt
endif

gcov_report: clean test
	lcov -t "test" --ignore-errors mismatch --no-external -o $(BUILD_DIR)/src/Google_tests/test.info -c -d .
	genhtml -o report $(BUILD_DIR)/src/Google_tests/test.info
	open report/index.html

t: clean clang test valgrind


# gcov_report: s21_containers_tests.o
# ifeq ($(OS), Linux)
# 	echo $(OS2)
# ifeq ($(OS2), ID=alpine)
# 	echo "For Alpine --------------------"
# 	$(CC) $(CFLAGS) s21_containers_tests.o s21_vector.cc -o test.out $(GFLAGS)
# else
# 	echo "For Ubuntu --------------------"
# 	$(CC) $(CFLAGS) s21_containers_tests.o s21_vector.cc -o test.out $(GFLAGS)
# endif
# else
# 	echo "For Apple --------------------"
# 	$(CC) $(CFLAGS) s21_containers_tests.o s21_vector.cc -o test.out -lgtest -lm --coverage
# endif
# 	./test.out
# 	lcov -t "test" -o test.info -c -d .
# 	genhtml -o report test.info
# 	open report/index.html


CXX = gcc
CPP_STD = -std=c++17
# CPPFLAGS = --coverage
TARGET = SmartCalc2_0
CXXFLAGS = -g -Wall -Wextra -Werror --coverage -lstdc++
GT_FLAGS = -lgtest -lgtest_main -lm
GCOV = --coverage
#  Project directories
BUILD_DIR = build
SRC_DIRS = src src/s21_view_qt
GT_DIRS = src src/google_tests
#  Project sourses
SRCS := $(shell find $(SRC_DIRS) -maxdepth 1 -name *.cc)
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)

#  Google test sourses
GT_SRCS := $(shell find $(GT_DIRS) -maxdepth 1 -name s21_*.cc)
GT_OBJS := $(GT_SRCS:%=$(BUILD_DIR)/%.o)

OS := $(shell uname -s)

ifeq ($(OS), Darwin)
	APPLICATION := SmartCalc2_0.app
	OPEN = open $(BUILD_DIR)/$(APPLICATION)
else
	APPLICATION := SmartCalc2_0
	OPEN = ./$(BUILD_DIR)/$(APPLICATION)
endif

all: apple

apple:
	cd src/s21_view_qt && qmake6 CONFIG+=qtquickcompiler && make
	mkdir -p $(BUILD_DIR)
	rm -rf build/$(APPLICATION)
	mv src/s21_view_qt/$(APPLICATION) build/

#  Google tests
test: clean $(GT_OBJS)
	mkdir -p $(BUILD_DIR)
	$(CXX) $(GT_OBJS) $(GT_FLAGS) $(CXXFLAGS) -o $(BUILD_DIR)/gtest.out
	./$(BUILD_DIR)/gtest.out

#  SmartCallc2.0 application
app: $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(BUILD_DIR)/$(TARGET)

# Build step for C++ source
$(BUILD_DIR)/%.cc.o: %.cc
	mkdir -p $(dir $@)
	$(CXX) $(CPP_STD) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

.PHONY: clean
clean:
	cd src/s21_view_qt && make clean
	rm -rf $(BUILD_DIR)/* test.info report src/s21_view_qt/.qmake.stash \
	src/build-SmartCalc2_0-Desktop-Debug build-SmartCalc2_0-Desktop_x86_darwin_generic_mach_o_64bit-Debug

clang:
	clang-format -style=file:materials/linters/.clang-format -n src/*.cc src/google_tests/*.cc src/*h src/s21_view_qt/*.cc src/s21_view_qt/*.h
	clang-format -style=file:materials/linters/.clang-format -i src/*.cc src/google_tests/*.cc src/*h src/s21_view_qt/*.cc src/s21_view_qt/*.h

open: all
	$(OPEN)

leak:
ifeq ($(OS), Darwin)
	echo $(OS)
	echo "For Aple --------------------"
	leaks -atExit -- ./$(BUILD_DIR)/$(APPLICATION)/Contents/MacOS/SmartCalc2_0
else
	echo $(OS)
	echo "For Ubuntu --------------------"
	CK_FORK=no valgrind --vgdb=no --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=$(BUILD_DIR)/RESULT_VALGRIND.txt $(BUILD_DIR)/$(APPLICATION)
	grep errors $(BUILD_DIR)/RESULT_VALGRIND.txt
endif

gcov_report: clean test
	lcov -t "test" --ignore-errors mismatch --no-external -o $(BUILD_DIR)/src/Google_tests/test.info -c -d .
	genhtml -o report $(BUILD_DIR)/src/Google_tests/test.info
	open report/index.html

t: clean clang app valgrind

# sudo update-alternatives --install /usr/bin/qmake qmake /lib/qt6/bin/qmake 100

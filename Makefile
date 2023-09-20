CXX = g++
CPP_STD:=-std=c++17
# CPPFLAGS = --coverage
TARGET:=SmartCallc2.0
CXXFLAGS = -g -Wall -Wextra -Werror --coverage #-lstdc++
GT_FLAGS = -lgtest -lgtest_main -lm
#  Project directories
BUILD_DIR := build
SRC_DIRS := src src/s21_view_qt
GT_DIRS := src src/google_tests
INC=-I/usr/include/x86_64-linux-gnu/qt6 -I/lib/qt6
#  Project sourses
SRCS := $(shell find $(SRC_DIRS) -maxdepth 1 -name *.cc)
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)

#  Google test sourses
GT_SRCS := $(shell find $(GT_DIRS) -maxdepth 1 -name s21_*.cc)
GT_OBJS := $(GT_SRCS:%=$(BUILD_DIR)/%.o)

OS := $(shell uname -s)

all: app

apple:
	cd src/s21_view_qt && qmake SmartCalc2_0.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug
	make -f src/s21_view_qt/Makefile qmake_all
	cd src/s21_view_qt && make -j8 && make clean
	mv src/s21_view_qt/SmartCalc2_0 build/

#  Google tests
test:$(GT_OBJS)
	$(CXX) $(CXXFLAGS) $(GT_OBJS) $(GT_FLAGS) -o $(BUILD_DIR)/gtest.out
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
	rm -rf $(BUILD_DIR)/* test.info report src/s21_view_qt/.qmake.stash

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
	CK_FORK=no valgrind --vgdb=no --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=$(BUILD_DIR)/RESULT_VALGRIND.txt $(BUILD_DIR)/$(TARGET)
	grep errors RESULT_VALGRIND.txt
endif

gcov_report: clean test
	lcov -t "test" --ignore-errors mismatch --no-external -o $(BUILD_DIR)/src/Google_tests/test.info -c -d .
	genhtml -o report $(BUILD_DIR)/src/Google_tests/test.info
	open report/index.html

t: clean clang app valgrind

# sudo update-alternatives --install /usr/bin/qmake qmake /lib/qt6/bin/qmake 100

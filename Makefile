CXX		  := g++
CXX_FLAGS := -Wall -Wextra -std=c++11 -ggdb

BIN		:= bin
SRC		:= src
INCLUDE	:= include
LIB		:= lib

LIBRARIES	:=
EXECUTABLE	:= main
UNIT_TEST   := unit_test


all: $(BIN)/$(EXECUTABLE)

test: $(BIN)/$(UNIT_TEST)

run: clean all
	clear
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(filter-out $(SRC)/testTDriver.cpp $(SRC)/testTClosedBox.cpp, $(wildcard $(SRC)/*.cpp))
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) -L$(LIB) $^ -o $@ $(LIBRARIES)

$(BIN)/$(UNIT_TEST): $(SRC)/test*.cpp $(SRC)/T*.cpp
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) -L$(LIB) $^ -o $@ $(LIBRARIES)

clean:
	-rm $(BIN)/*

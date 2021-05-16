# name compiler
CC := g++

# flag parametres
CFLAG := -Wall
CFLAG += -std=c++11

# source files
SRC := $(notdir $(wildcard *.cpp))

# binary files
BIN := $(patsubst %.cpp, %.out, $(SRC))

# library parametres
LIB := -I../build/include/
LIB += -L../build/library/
LIB += -lgl++
LIB += -framework OpenGL
LIB += -lglfw

# mode list
.PHONY: build clean

# build mode
build: $(BIN)

# compile
%.out: %.cpp
	@echo "[COMPILING] $<"
	@$(CC) $(CFLAG) $(LIB) $< -o $@

# clean mode
clean:
	@echo "[CLEANING]"
	@rm -f *.out

# name project
TAG := libgl++

# name compiler
CC := g++

# flag parametres
CFLAG := -Wall
CFLAG += -std=c++11

# source files
SRC := $(notdir $(wildcard core/*.cpp))
SRC += $(notdir $(wildcard modules/window/*.cpp))
SRC += $(notdir $(wildcard modules/object/*.cpp))
# @echo $(SRC)
# $(SRC)

# object files
OBJ := $(addprefix build/object/, $(patsubst %.cpp, %.o, $(SRC)))

# include parametres
INC := -Iinclude/

# library parametres
LIB := -Ilibrary/stb/
LIB += -Ilibrary/glfw/include/
LIB += -Ilibrary/freetype2/include/

# mode list
.PHONY: build clean

# release mode
build: build/library/$(TAG).a

build/library/$(TAG).a: $(OBJ)
	@echo "[BUILD]"
	@cp -R include/ build/include/
	@ar cr build/library/$(TAG).a $(OBJ)

# compile
build/object/%.o: core/%.cpp
	@mkdir -p build/include/
	@mkdir -p build/library/
	@mkdir -p build/object/
	@$(CC) $(CFLAG) $(INC) $(LIB) -c $< -o $@

build/object/%.o: modules/window/%.cpp
	@mkdir -p build/include/
	@mkdir -p build/library/
	@mkdir -p build/object/
	@$(CC) $(CFLAG) $(INC) $(LIB) -c $< -o $@

build/object/%.o: modules/object/%.cpp
	@mkdir -p build/include/
	@mkdir -p build/library/
	@mkdir -p build/object/
	@$(CC) $(CFLAG) $(INC) $(LIB) -c $< -o $@

# clean mode
clean:
	@echo "[CLEANING]"
	@rm -r -f build/

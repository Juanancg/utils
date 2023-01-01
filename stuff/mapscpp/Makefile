CXX       := g++
CXX_FLAGS := -std=c++17 -ggdb3

BIN     := bin
SRC     := src
INCLUDE := include

LIBRARIES   :=
EXECUTABLE  := $(BIN)/main
CODE_SRC  := $(wildcard src/*.cpp)

.PHONY: all executable clean fclean

all: executable

executable : $(EXECUTABLE)

$(EXECUTABLE): $(CODE_SRC) | $(BIN)
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) $^ -o $@ $(LIBRARIES)

$(BIN):
	mkdir $@

clean:
	@$(RM) -rv $(BIN) 

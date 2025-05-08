# Compiler
CXX = g++

# Compiler Flags
CXXFLAGS = -std=c++11 -Wall -O2

# Source and Output Files
SRC = Hedge.cpp
OUT = hedge

# Default target: Compile the program
all: $(OUT)

# Compile the program
$(OUT): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(OUT)

# Run the program
run: $(OUT)
	./$(OUT)

# Clean up compiled files
clean:
	rm -f $(OUT)
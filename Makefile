# Compiler
CXX := clang++
CXXFLAGS := -Wall -std=c++17 -Iinclude

# Directories
SRC_DIR := src
BUILD_DIR := build
OBJ_DIR := $(BUILD_DIR)/obj
BIN := main

# Source and object files
SRCS := $(wildcard $(SRC_DIR)/*.cc)
OBJS := $(patsubst $(SRC_DIR)/%.cc, $(OBJ_DIR)/%.o, $(SRCS))

# Default target
all: $(BIN)

# Linking
$(BIN): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compiling
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cc | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Create object dir
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Clean
clean:
	rm -rf $(BUILD_DIR) $(BIN)

.PHONY: all clean

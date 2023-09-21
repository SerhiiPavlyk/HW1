# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall

TARGET = main

# Source files
SRC = pch.cpp WindowsAPI.cpp LinuxAPI.cpp Network.cpp Common.cpp Client.cpp Server.cpp main.cpp

# Object files
OBJ = $(SRC:.cpp=.o)

# Header files
HDRS = pch.h WindowsAPI.h LinuxAPI.h Network.h Common.h Client.h Server.h

# Build the target
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

# Compile source files
%.o: %.cpp $(HDRS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up object files and the target executable
clean:
	rm -f $(OBJ) $(TARGET)

# Specify the "all" target, which will be built when you run 'make'
all: $(TARGET)

.PHONY: clean all

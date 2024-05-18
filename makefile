CXX = g++
CXXFLAGS = -Wall -J -std=c++11 -O2
SOURCES = $(wildcard *.cpp)
HEADERS = $(wildcard *.h) 
TARGET = main

all: $(TARGET)

$(TARGET): $(SOURCES) $(HEADERS)
	$(CXX) $(CXXFLAGS) $^ $(LDFLAGS) -o $@
debug: $(TARGET)
	gdb $<
clean:
	rm -f $(TARGET)
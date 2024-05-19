CXX = g++
CXXFLAGS = -Wall -std=c++20 -O2
SOURCES = main.cpp CLI.cpp Course.cpp Semester.cpp StudyPlan.cpp Student.cpp
HEADERS = CLI.h Course.h Semester.h StudyPlan.h Student.h
TARGET = main

all: $(TARGET)

$(TARGET): $(SOURCES) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET)

debug:
	gdb $(TARGET)

clean:
	rm -f $(TARGET)

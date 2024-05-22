CXX = g++
CXXFLAGS = -Wall -std=c++20 -O2

SRCS = main.cpp CLI.cpp Course.cpp Semester.cpp StudyPlan.cpp Student.cpp cgpacalc.cpp
OBJS = $(SRCS:.cpp=.o)
EXEC = main

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f $(OBJS) $(EXEC)

CXX = g++
CXXFLAGS = -Wall -Wextra -Wpedantic -Wshadow -Wconversion -Wnon-virtual-dtor \
           -Wold-style-cast -Woverloaded-virtual -Wnull-dereference \
           -Wdouble-promotion -Wformat=2 -std=c++23 -g

SRCS = ej1.cpp test.cpp
EXEC = test_vuelo

all: $(EXEC)

$(EXEC): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(SRCS)

clean:
	rm -f $(EXEC) *.o

run: $(EXEC)
	./$(EXEC)

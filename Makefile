CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

TARGET = RoutePlanner

SRCS = main.cpp Graph.cpp RouteFinder.cpp FileManager.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

CXX = g++
CXXFLAGS = -Wall -std=c++11

SRCS = main.cpp reward.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = main

$(TARGET) : $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o $(TARGET)

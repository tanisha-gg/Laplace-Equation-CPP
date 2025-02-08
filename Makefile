CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -O2
LDFLAGS = -llapacke -lnetcdf

SRCS = main.cpp laplace_solver.cpp init.cpp iteration.cpp output.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = laplace_solver

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS) $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET) output.nc output.txt

.PHONY: all clean

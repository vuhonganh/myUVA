CXX = g++
LD = g++
CC = g++
CXXFLAGS = -g -std=c++11 -Wall


SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)
EXE = main


all: $(EXE)

$(EXE): $(OBJS)

run: $(EXE)
	./$<

out: $(EXE) input
	./$< < input > output

.PHONY: clean

clean:
	rm -rf $(EXE) $(OBJS)

CXX = g++
LD = g++
CC = g++
CXXFLAGS = -g -std=c++11 -Wall


SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)
EXE = main


all: $(EXE)

$(EXE): $(OBJS)

run: $(EXE)
	./$< < input

out: $(EXE) input
	./$< < input > output

.PHONY: clean

clean:
	rm -rf $(EXE) $(OBJS)

# Makefile to build an executable named proj4 from main.cpp

#The c++ compiler defined as g++
CXX = g++

#Compiler Flags
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

OBJECTS = fileio.o mst.o opt2.o tspChristofides.o main.o
SOURCES = fileio.cpp mst.cpp opt2.cpp tspChristofides.cpp main.cpp
HEADERS = fileio.hpp mst.hpp opt2.hpp tspChristofides.hpp

all: proj4

proj4: ${OBJECTS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o proj4

${OBJECTS}: ${SOURCES}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)
	
clean:
	rm -rf *o all
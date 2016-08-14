/*
 *  fileio.cpp
 *
 *  Created on: Nov 27, 2015
 *  Author: Susie Kuretski, Ava Petley, Robert Sparks
 *  CS325, Project 4
 *  Description: implementation of file I/O and other file functions
 */

#include "fileio.hpp"
#include <climits>
//Get number of cities from input file via getline
int countCities(std::string filename){
	std::ifstream infile(filename.c_str(), std::ifstream::in);
	std::string line;
	int numOfLines = 0;
	while(std::getline(infile, line)){
		numOfLines++;
	}
	return numOfLines;
}

/*Description: Reads a file in, takes 1) city id 2) x coordinate 3) y coordinate
  Parameters: Graph g (to store all city information), input filename, and number
  of cities
  Pre-condition: Input file has city information in the format of:
-----------------------------------------------------------------------
  0 4 3
  1 4 9
-----------------------------------------------------------------------
  where the first number is city id, the second number is x-coord, and
  third number is y-coord
  Post-condition: Graph contains all city information (kept as structs),
  return integer indicating number of cities
*/
void fileImportData(Graph *g, std::string filename, int numCities){
	std::ifstream infile(filename.c_str(), std::ifstream::in);
	int i = 0;
	int n;
	int m;
	int c;
	while(infile >> c >> n >> m ){
		g->citySet[i].cityNum = c;
		g->citySet[i].x = n;
		g->citySet[i].y = m;
		i++;
	}
	infile.close();
}





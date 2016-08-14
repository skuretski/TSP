/*
 * fileio.hpp
 *
 *  Created on: Nov 27, 2015
 *  Author: Susie Kuretski, Ava Petley, Robert Sparks
 *  CS325, Project 4
 *  Description: Header file for file I/O and other various file functions
 */

#ifndef FILEIO_HPP_
#define FILEIO_HPP_

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include "mst.hpp"

int countCities(std::string filename);
void fileImportData(Graph *g, std::string filename, int numCities);


#endif /* FILEIO_HPP_ */

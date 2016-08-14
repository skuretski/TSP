/*
 *  tspChristofides.hpp
 *
 *  Created on: Nov 27, 2015
 *  Author: Susie Kuretski, Ava Petley, Robert Sparks
 *  CS325, Project 4
 *  Description: header file for TSP-Christofides implementation
 */

#ifndef TSPCHRISTOFIDES_HPP_
#define TSPCHRISTOFIDES_HPP_

#include <climits>
#include <cstdlib>
#include "mst.hpp"

std::vector<std::vector < int> >oddMatching(int numCity, std::vector< std::vector <int> >adjM, Graph *g );
std::vector<int > tsp(std::vector<std::vector<int > > mst, std::vector<std::vector<int > > oddPM, int numCity);
void hamil(std::vector<int > &vec);

#endif /* TSPCHRISTOFIDES_HPP_ */

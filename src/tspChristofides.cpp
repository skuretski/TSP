/*
 *  tspChristofides.cpp
 *
 *  Created on: Nov 27, 2015
 *  Author: Susie Kuretski, Ava Petley, Robert Sparks
 *  CS325, Project 4
 *  Description: Implementation of Christofides algorithm for TSP
 */

#include "tspChristofides.hpp"
#include <iostream>
#include <stack>
#include <cstdio>
#include <algorithm>

std::vector<std::vector < int> >oddMatching(int numCity, std::vector< std::vector <int> >adjM, Graph *g )
{
//Find vertices from MST with odd degree
//Minimum Matching -combined these two steps together (uses greedy method)
   unsigned int i = 0;
   std::vector<int > oddVertices;
   std::vector<std::vector<int > > matrix(numCity, std::vector<int>());

   //Making vector of odd degree vertices
   for (; i < adjM.size();i++ ){
	   if(adjM[i].size() %2!=0){//get vector row size, if its odd then copy row to new vector
		   oddVertices.push_back(i);
	   }
   }
   //Minimum Matching (greedy)
   int near, size;
   std::vector<int>::iterator start, temp;
   while(oddVertices.size() != 0){
	   //Vector markers
	   std::vector<int >::iterator end, next;
	   end = oddVertices.end();
	   start = oddVertices.begin();
	   size = INT_MAX;	//To make a very big starting size >> see following if statement
	   for(next = oddVertices.begin() + 1; next != end; next++){	//next is marker to next odd vertice
		   //greedy matching
		   if(g->edges[*start][*next].cost < size){
			   size = g->edges[*start][*next].cost;
			   near = *next;
			   temp = next;
		   }
	   }
	   matrix[*start].push_back(near);	//pushing back edge
	   matrix[near].push_back(*start);	//pushing back mirrored edge
	   oddVertices.erase(temp);
	   oddVertices.erase(start);		//Removing odd vertex from vector
   }
   return matrix;
}

//Matching unioned with MST, then Euler tour and Hamiltonian cycle
std::vector<int > tsp(std::vector<std::vector<int > > mst, std::vector<std::vector<int > > oddPM, int numCity){
	std::vector<std::vector<int > > tsp(numCity, std::vector<int >());
	unsigned int i, j;
	for(i = 0; i < mst.size(); i++){
		for(j = 0; j < mst[i].size(); j++){
			tsp[i].push_back(mst[i][j]);
		}
	}
	for(i = 0; i < oddPM.size(); i++){
		for(j = 0; j < oddPM[i].size(); j++){
			tsp[i].push_back(oddPM[i][j]);
		}
	}

//************** Euler tour ******************************************************//
	std::vector<int> eTour;
	std::stack<int> vertexStack;
    //visit each node in order and record the path to a 1-d vector
	int next = 0, last = 0, neighbor = 0;
	eTour.push_back(next);
	while(!vertexStack.empty() || tsp[next].size() > 0){
		if(tsp[next].size() == 0){
			last = vertexStack.top();
			vertexStack.pop();
			next = last;
		}
		else{
			neighbor = tsp[next].back();
			tsp[next].erase(tsp[next].begin() + tsp[next].size()-1);
			for(i = 0; i < tsp[neighbor].size(); i++){
				if(tsp[neighbor][i] == next){
					tsp[neighbor].erase(tsp[neighbor].begin() + i);
				}
			}
			if(tsp[next].size() > 1){
				vertexStack.push(next);
			}
			next = neighbor;
			eTour.push_back(next);
 		}

	}
	hamil(eTour);
	return eTour;
}

void hamil(std::vector<int > &vec){
 	int size = vec.size();
 	std::vector<int > v;
 	int i;
 	unsigned int k;
 	int val;
 	int val2;
 	int add;
	v.push_back(vec[0]);
 	for(i=1; i<size; i++){
		add=1;
		for(k=0; k<v.size(); k++){
 				val = vec[i];
 				val2= v[k];
 				if(val == val2){
 					vec.erase (vec.begin() + i);
 					add=0;
					i=i-1;
 					size=size-1;
 					k=v.size();
 				 }
 		}
 		if(add==1){
 			v.push_back(vec[i]);
 		}
 	}
}

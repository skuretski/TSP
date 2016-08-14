/*
 *  mst.hpp
 *
 *  Created on: Nov 29, 2015
 *  Author: Susie Kuretski, Ava Petley, Robert Sparks
 *  Description: Header for MST.cpp; includes structs to make graph (City, Edge, Graph)
 */

#ifndef MST_HPP_
#define MST_HPP_

#include <vector>

//City acts as "Vertex"
struct City{
	int x;
	int y;
	int cityNum;
	City(){};
	City(int city, int n, int m, bool visit, bool odd, int p){
		cityNum = city;
		x = n;
		y = m;
	}
};
struct Edge{
	City *source;
	City *destination;
	int cost;
	Edge(City *s, City *d, int c){
		source = s;
		destination = d;
		cost = c;
	}
	Edge(){};
};

struct Graph{
	int E, V;
	Edge **edges;
	City *citySet;
};

Graph* createGraph(int size);
int distance(struct City u, struct City v);
void fillGraphEdges(Graph *g, int numCities);
void deleteGraph(Graph *g, int numCities);
int minKey(int key[], bool inMST[], int n);
std::vector<std::vector<int > > prim(Graph *g, int num);


#endif /* MST_HPP_ */

/*
 *  mst.cpp
 *
 *  Created on: Nov 29, 2015
 *  Author: Susie Kuretski, Ava Petley, Robert Sparks
 *  Description: Implementation of finding MST with a graph
 */

// MST using Prim

#include "mst.hpp"
#include <cmath>
#include <algorithm>
#include <vector>
#include <climits>
#include <iterator>
#include <cstdlib>
#include <iostream>

typedef std::vector<int> vect;
Graph* createGraph(int size){
	Graph *newGraph = new Graph[size];
	newGraph->citySet = new City[size];
	newGraph->edges = new Edge*[size];
	return newGraph;
}

//Distance (edge weight) calculation
int distance(struct City u, struct City v){
	int dist = 4;
	int dx = pow((float)(u.x - v.x), 2);
	int dy = pow((float)(u.y - v.y), 2);
	dist = (floor((float) (sqrt(dx + dy)) + 0.5));	//0.5 to compensate for rounding
	return dist;
}

void fillGraphEdges(Graph *g, int numCities){
	int i, j;
	for(i = 0; i < numCities; i++){
		g->edges[i] = new Edge[numCities];
		for(j = 0; j < numCities; j++){
			City *pointerA = &g->citySet[i];
			City *pointerB = &g->citySet[j];
			g->edges[i][j].source = pointerA;
			g->edges[i][j].destination = pointerB;
			g->edges[i][j].cost = distance(g->citySet[i], g->citySet[j]);
		}
	}
}

//City visited (key) is set to INT_MAX initially (infinity)
//See CLRS page 634
//http://www.geeksforgeeks.org/greedy-algorithms-set-5-prims-minimum-spanning-tree-mst-2/
std::vector<std::vector<int > > prim(Graph *g, int num){
	//Structures for Prim
	bool *inTree = new bool[num];
	int *key = new int[num];
	int *parent = new int[num];
	//Adjacency Matrix
	std::vector<std::vector< int > > adjMatrix(num, vect() );

	int i, u = 0;

	//Keys set to INF and marks all to be not in MST
	for(i = 0; i < num; i++){
		key[i]= INT_MAX;
		inTree[i] = false;
	}
	//Set root to zero
	key[0] = 0;
	parent[0] = INT_MIN;

	//While queue is not empty (all vertices not in MST)
	for(i = 0; i < num; i++){
		int v = minKey(key, inTree, num);
		inTree[v] = true;
		for(u = 0; u < num; u++){
			//If uv is not in tree and the edge is less than key
			if((g->edges[u][v].cost && inTree[u] == false) && (g->edges[u][v].cost < key[u])){
				parent[u] = v;
				key[u] = g->edges[u][v].cost;
			}
		}
	}
	for(i = 0; i < num; i++){
		int j = parent[i];
		if(j != INT_MIN){
			adjMatrix[i].push_back(j);
			adjMatrix[j].push_back(i);
		}
	}
	delete [] inTree;
	delete [] key;
	delete [] parent;
	return adjMatrix;
}
//Finds the minimum key (pseudo-min heap idea)

int minKey(int key[], bool inMST[], int n){
	int min = INT_MAX;
	int minIdx;
	int i;
	for(i = 0; i < n; i++){
		if(inMST[i] == false && key[i] < min){
			min = key[i];
			minIdx = i;
		}
	}
	return minIdx;
}
//Memory clean up for dynamic arrays
void deleteGraph(Graph *g, int numCities){
	if(g != 0){
		int i;
		for(i = 0; i < numCities; i++){
			delete [] g->edges[i];
		}
		delete [] g->edges;
		delete [] g->citySet;
		delete [] g;
	}
}



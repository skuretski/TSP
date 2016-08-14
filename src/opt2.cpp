/*
 *  opt2.cpp
 *
 *  Created on: Dec 1, 2015
 *  Author: Ava Petley
 */

#include "mst.hpp"
#include "opt2.hpp"
#include <cmath>
//function to calculate distance for a tour given as an array
int totalDis(Graph *g, std::vector<int>  &vec, int aSize){
//variables for interating loops and holding distances
	int i;
	int j;
	int dist;
	int totald=0;
	int u;
	int v;
	for(i = 0; i<aSize;i++){
	//u gets from the array the starting vertex in an edges
		u=vec[i];
		//this is for the typical edged in the path
		if(i<(aSize-1)){
			j=i+1;
			v=vec[j];
		}
		//this is for the edge that complete the circular path
		else{
			v=vec[0];
		}
		//this gets the distance of the edge
		dist= g->edges[u][v].cost;
		//this will add up the edges and provide a total distance for the path
		totald=totald+dist;
	}
	//this returns the total distance
	return totald;
}
//this function will swap the vertices in a tour to check for inefficiencies it takes the graph and the tour as an array
int swap(Graph *g, std::vector<int>  &vec, int aSize){
	//this temp vector will hold the section of the tour that is effected
	std::vector<int> TempArr (4,0);
	//variables for loops
	int i;
	int j=0;
	//current is the current distance for the section under review
	int current;
	//this hold the the vertex being rearranged
	int val;
	//this is the total after the swap
	int newTotal;
	//loop variables
	int k=0;
	//loop to travel through tour
	while(k<(aSize)){
	//loop to fill temp array with the next section to look at
	for(i=0; i<4; i++){
		TempArr[i]=vec[j];
		j++;
	}
	current=totalDis(g, TempArr, 4);
	//swapping values
	val = TempArr[2];
	TempArr[2]=TempArr[1];
	TempArr[1]=val;
	//distance of the swapped section
	newTotal=totalDis(g, TempArr, 4);
	//if new value is less distance than the current then it is added it replaces the old piece in the full tour
	if(newTotal<current){
		//returns to starting point of altered section
		j=j-4;
		for(i=0; i<4; i++){
			vec[j]=TempArr[i];
			j++;
		}
	}
	j=j-3;
	k++;
	}
	int total=totalDis(g,vec, vec.size());
	return total;
}


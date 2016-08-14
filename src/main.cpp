/*
 *  main.cpp
 *
 *  Created on: Nov 25, 2015
 *  Authors: Susan Kuretski, Ava Petley, Robert Sparks
 *  CS325-401, Project 4
 *  Implementation of TSP
 */

#include "fileio.hpp"
#include "tspChristofides.hpp"
#include "opt2.hpp"
#include <ctime>

int main( int argc, char *argv[] ){
	std::string inFileName;
	std::vector< std::string > tokens;
	std::string token;
	float start_time, end_time, elapsed_time;
	start_time = std::clock();
	unsigned int i;

	//Command Line Handling
	if(argc != 2){
		std::cout << "Please enter a file name to continue." << std::endl;
		return 0;
	}
	else if(argc > 0){
		inFileName = argv[1];
		std::istringstream iss(inFileName);
		while(std::getline(iss, token, '.')){
			if(!token.empty())
				tokens.push_back(token);
		}
	}
	std::ifstream inFile(inFileName.c_str(), std::ifstream::in);
	if(!inFile){
		std::cerr << "The file was not found." << std::endl;
		return -1;
	}

	//Importing data into graph
	int numCities = countCities(inFileName);
	Graph *graph = createGraph(numCities);
	fileImportData(graph, inFileName, numCities);
	fillGraphEdges(graph, numCities);

	//Prim's
	std::vector<std::vector<int> > adjMatrix = prim(graph, numCities);

	//Min-weight matching with odds
	std::vector<std::vector<int > > adjMatrix2 = oddMatching(numCities, adjMatrix, graph);

	//Euler + Hamiltonian
	std::vector<int > tspResult = tsp(adjMatrix, adjMatrix2, numCities);

	//2-Opt
	int result = swap(graph, tspResult, numCities);

	//Appending/Making output file
	std::string outFile = tokens[0] + ".txt" + ".tour";
	std::ofstream outPutFile(outFile.c_str());
	outPutFile << result << std::endl;
	for(i = 0; i < tspResult.size(); i++){
		outPutFile << tspResult[i] << std::endl;
	}
	//Memory clean up
	deleteGraph(graph, numCities);

	//Clocking
	end_time = std::clock();
	elapsed_time = end_time - start_time;
	std::cout << inFileName << std::endl;
	std::cout << "Execution time " << std::fixed << elapsed_time / CLOCKS_PER_SEC << " sec" << std::endl<< std::endl;
	return 0;
}








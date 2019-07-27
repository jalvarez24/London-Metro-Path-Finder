#pragma once
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include "Graph.h"

using namespace std;

//Reads a list of (int, string) pairs from station_names.txt that represents respective
//station# and station name
//-Returns a vector of strings where vector index corresponds to station#
//-Throws error and closes program if error is detected while opening file
vector<string> readStationNames(const string& filename) {
	
	vector<string> v;	
	string station;	//varible for station being read in from file
	int id;			//variable for id of station read in from file

	ifstream stationsFile;
	stationsFile.open(filename);

    if (!stationsFile){
        cout << "Unable to open file " << filename << endl;
        exit(0);
    }

	v.insert(v.end(), " ");	//inserts empty space to first index of vector

	while (stationsFile >> station >> id)
	{
		v.insert(v.end(), station);	//now first station added to vector will be indexed by 1, and so on
	}								//until can't read in station and id
							
	stationsFile.close();

	return v;
}

//Reads a list of (int, int) pairs from station_route.txt that represent
//connections between stations (actual station name gotten from station_names.txt)
//-Returns a graph class ptr representing these station links
//-Throws error and closes program if error is detected while opening file
Graph* buildGraphfromDatafile(const std::string& filename) {

	int id1;	//represent set of 
	int id2;	//adjacent stations	

	ifstream routesFile;
	routesFile.open(filename);

    if (!routesFile){
        cout << "Unable to open file " << filename << endl;
        exit(0);
    }
	Graph* g = new Graph(321);

	while (routesFile >> id1 >> id2){
		g->insertEdge(id1, id2);
    }
    
    routesFile.close();
    
    return g;
}

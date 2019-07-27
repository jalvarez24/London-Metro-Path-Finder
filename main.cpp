/*
London Metro Path Finder
By Jayro Alvarez
Project for Data Struture Course

This program demonstrates graph traversal using Depth-First Search.
The graph is represented by an adjacency matrix and is built by reading in a file with 320 different stations (int->string)
and another file showing all the connections between the stations (int->int).

Graph.h file:
 -Contains graph class definition and its functions
 
utilities.h file (contains to important utility functions)
 -readStationNames(string filename) func.: returns string vector where int index maps to correct string name of station, built
    from the file that is passed in as parameter
 -buildGraphfromDatafile(string filename) func.: returns graph pointer to a graph with edges built from the file with int->int
    connections
 
 station_names.txt: contains all stations and their respective station number (int->string)
 station_route.txt: contains all the connections between stations (int->int)
 */

#include <iostream>
#include <vector>
#include "utilities.h"
#include "Graph.h"

using namespace std;

int main() {
    //build a graph of the London Underground tube routes
    Graph* g = buildGraphfromDatafile("station_route.txt");
    
    //read the station names
    vector<string> stationNames = readStationNames("station_names.txt");
    
    //getting a path from Whitechapel(313) -> Charing_Cross(55)
    
    
    //random from and destination values used, can be changed...
    int from = 313; // station id=313 represents Whitechapel
    int destination = 55; // station id=55 represents Charing_Cross
    
    cout << "Getting path from " << stationNames[from] << " to " << stationNames[destination] << "..." << endl;
    
    //populates vector<int> stations with a valid path from 'from' to 'destination' variables
    vector<int> stations = g->getPath(from, destination);
    
    //if no path was found
    if(stations.size() == 0){
        cout << "There is no valid path between stations" << endl;
    }
    
    //otherwise, for every path in found, print out the name of that station
    else{
        cout << "There are " << stations.size() << " stations in between: " << endl;
        for (unsigned int i = 0; i < stations.size(); i++){
            cout << stationNames[stations[i]] << endl;
        }
    }
    
    //One possible path: Whitechapel(313) -> Aldgate_East(4) -> Liverpool_Street(170) -> Bank(14) ->
    //Monument(180) -> Cannon_Street(49) -> Mansion_House(175) -> Blackfriars(26) -> Temple(272) ->
    //Embankment(94) -> Charing_Cross(55)
    
    return 0;
}

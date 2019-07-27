# London-Metro-Path-Finder (Fall 2016)
Unfinished Project for CPSC131 Data Structures Course. Uses DFS (Depth-First Search) to find a valid path between two London Metro stations.

By Jayro Alvarez

# What does the code do?
Takes in two text files:
  -1: Names of all stations (string) and corresponding stations number (int)
  -2: All connections between stations (int to int)

Creates a 2D matrix to remember all connections between stations. Will use DFS to search through these connections until/if one is found and returns first one.

Stores the path in a vector while it's looking for paths and returns it at the end. (Returns empty vector if no path is found)

*Implements an unordered set to keep track of already visited stations to increase efficiency. Paths do not have given distances so unable to find the shortest path (in terms of distance)

# Sample Run of Project
![Image of Sample Run](https://raw.githubusercontent.com/jalvarez24/London-Metro-Path-Finder/master/London%20Metro%20Images/Sample%20Run.png)

# How to improve?
I would try to improve my project by finding a way to return the path that travels along the least amount of stations.

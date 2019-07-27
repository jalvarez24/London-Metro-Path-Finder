# London-Metro-Path-Finder (Fall 2016)
Unfinished Project for Data Structures Course. Uses DFS (Depth-First Search) to find a valid path between two London Metro stations.
By Jayro Alvarez

# What does the code do?
Takes in two text files:
  -1: Names of all stations (string) and corresponding stations number (int)
  -2: All connections between stations (int to int)

Creates a 2D matrix to demonstrate all connections between matrix. Will use DFS to search through these connections until/if one is found and returns first one.

Implements a C++ unordered set to keep track of already visited stations to increase efficiency. Path do not have given distances so unable to find the shortest path (in terms of distance)

# How to improve?
I would try to improve my project by finding a way to return the path that travels along the least amount of stations.

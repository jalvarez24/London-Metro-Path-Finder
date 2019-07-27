#pragma once
#include <vector>
#include <unordered_set>

class Graph {
public:
	// initialize an undirected graph that can store at most n vertices
	Graph(const int n) {
        matrix.resize(n);
        for(int i = 0; i < n; i++) matrix[i].resize(n);
	}

	// insert an edge between vertices u and v & v and u
    // (creates a symmetrical 2d array
	void insertEdge(int u, int v) {
		matrix[u][v] = 1;
        matrix[v][u] = 1;
	}

	// return first unvisited node
    int adjacentVertices(int v, std::unordered_set<int>& seen) {
        
		for (int i = 1; i < 321; i++){
			if(matrix[v][i] == 1 && seen.find(i) == seen.end()){
                seen.insert(i);
                return i;
			}
		}
        
        //if none are found, return 0
        return 0;
	}

	// return a list of vertices that appear between v and w, starting with v and ending with w
	// vertices should not be repeated
	std::vector<int> getPath(int start, int destination) {
        
        std::vector<int> path;
        std::unordered_set<int> seen;
        
        path.push_back(start);
        seen.insert(start);
        
        return helper(path, seen, destination);
	}
    
    //helper function for getPath
    std::vector<int> helper(std::vector<int> path, std::unordered_set<int>& seen, const int& destination){
        
        if(path.back() == destination) return path;
        
        int adj = adjacentVertices(path.back(), seen);
        
        //means we've hit a dead end
        if(adj == 0){
            path.pop_back();
            return helper(path, seen, destination);
        }
        
        path.push_back(adj);
        return helper(path, seen, destination);
    }
    
	// member variables and functions to implement the public member functions
    std::vector<std::vector<int>> matrix;
};

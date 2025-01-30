#pragma once
#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <climits>
#include <stdexcept>

using namespace std;

struct Edge 
{
    int to;
    int weight;
    int green;
    int red;
};

struct HeapNode 
{
    int weight;
    int from;
};

class Graph
{
    public:
    int V, E, startNode, endNode;
    vector<vector<Edge>> adj; 
    vector<int> dist;
    
    Graph(int a, int b);
    
    void addEdge(int source, int dist, int weight, int green, int red);

};

int calculateDelay(int currentTime, int greenTime, int redTime);

int shortestPath(Graph myGraph);
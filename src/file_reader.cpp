#include "../includes/file_reader.h"

Graph readGraphFromFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) 
    {
        throw runtime_error("Error: Could not open file: " + filename);
    }
    if (file.peek() == ifstream::traits_type::eof()) 
    {
        throw EmptyFileError("Error: File is empty: " + filename);
    }
    int V, E;
    string line;
    getline(file, line);
    stringstream ss(line);
    if (!(ss >> V >> E)) 
    {
        throw FileFormatError("Error: Invalid format for vertices and edges count in the first line of " + filename);
    }
    if (V < 2 || E < 1 || V > 1000 || E > 10000) 
    {
        throw FileFormatError("Error: Number of vertices must be (1000>=V>=2), and edges must be (10000>=E>=1) in " + filename);
    }
    auto myGraph = Graph(V,E);
    for (int i = 0; i < E; i++) 
    {
        if (!getline(file, line)) 
        {
            throw FileFormatError("Error: Expected edge data but file ended, at line" + to_string(i + 2) + " of" + filename);
        }
        stringstream ss(line);
        int source, dist, weight, green, red;
        if (ss >> source >> dist >> weight >> green >> red) 
        {
            // Дополнить если что
            if (source < 0 || dist < 0 || source >= V || dist >= V ||
             weight < 1 || weight > 100 || green >10 || green < 0 || red > 10 || red < 0) 
            {
                throw InvalidVertexError("Error: The index of a vertex or other value is beyond the acceptable range. At line " + to_string(i + 2) + " of " + filename);
            }
            myGraph.addEdge(source, dist, weight, green, red);
        } 
        else 
        {
            throw FileFormatError("Error: Invalid format for edge data at line " + to_string(i + 2) + " of " + filename);
        }
    }
    if(!getline(file, line))
    {
        throw FileFormatError("Error: Expected start and end points after edges, but file ended");
    }
    stringstream ss2(line);
    if (!(ss2 >> myGraph.startNode >> myGraph.endNode)) 
    {
        throw FileFormatError("Error: Invalid format for start and end point after edges");
    }
    if (myGraph.startNode < 0 || myGraph.endNode < 0 || myGraph.startNode >= V || myGraph.endNode >= V )
    {
        throw PathPointsError("Error: Invalid start or end point");
    }
    return myGraph;
}
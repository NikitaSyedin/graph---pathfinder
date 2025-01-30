#pragma once
#include <fstream>
#include <string>
#include <sstream>
#include <utility>
#include "HeapDijkstra.h"


Graph readGraphFromFile(const string& filename);

class FileFormatError : public runtime_error 
{
    public:
        FileFormatError(const string& msg) : runtime_error(msg) {}
};

class EmptyFileError : public runtime_error 
{
    public:
        EmptyFileError(const string& msg) : runtime_error(msg) {}
};

class InvalidVertexError : public runtime_error 
{
    public:
        InvalidVertexError(const string& msg) : runtime_error(msg) {}
};

class PathPointsError : public runtime_error 
{
    public:
        PathPointsError(const string& msg) : runtime_error(msg) {}
};
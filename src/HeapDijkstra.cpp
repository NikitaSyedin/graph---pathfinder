#include "../includes/HeapDijkstra.h"


Graph::Graph(int a, int b)
{
    this->V = a;
    this->E = b;
    this->adj.resize(V);
    this->dist.resize(V, INT_MAX);
}

void Graph::addEdge(int source, int dist, int weight, int green, int red)
{
    this->adj[source].push_back({dist, weight, green, red});
    this->adj[dist].push_back({source, weight, green, red});
}

int calculateDelay(int currentTime, int greenTime, int redTime) 
{
    if (greenTime + redTime == 0)
        return 0;
    int period = greenTime + redTime;
    int timeInPeriod = currentTime % period;
    if (timeInPeriod < greenTime) 
    {
        return 0;
    } 
    else 
    {
        return period - timeInPeriod;
    }
}

int shortestPath(Graph myGraph)
{

    auto myComparator = [](const HeapNode& a, const HeapNode& b) {
        return a.weight > b.weight;
    };
    priority_queue<HeapNode, vector<HeapNode>, decltype(myComparator)> pq(myComparator);
    
    pq.push({0, myGraph.startNode});
    myGraph.dist[myGraph.startNode] = 0;

    while (!pq.empty()) 
    {
        int u = pq.top().from;
        pq.pop();
        if(u == myGraph.endNode)
        {
            break;
        }
        else
        {
            for (auto x : myGraph.adj[u]) 
            {
                
                int v = x.to;
                int weight = x.weight;
                int greenTime = x.green;
                int redTime = x.red;
                int delay = calculateDelay(myGraph.dist[u], greenTime, redTime);

                if (myGraph.dist[v] > myGraph.dist[u] + weight + delay) {
                    myGraph.dist[v] = myGraph.dist[u] + weight + delay;
                    pq.push({myGraph.dist[v], v});
                }
            }
        }
    }
    if(myGraph.dist[myGraph.endNode] == INT_MAX) 
    {
        return -1;
    }
    return myGraph.dist[myGraph.endNode];
}

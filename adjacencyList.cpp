#include <iostream>
#include <vector>
#include <queue>

// adjacency list implementation using std::vector

class adjacencyList
{
private:
  std::vector<std::vector<int>> adjList;
  bool isDirected;

public:
  adjacencyList(int vertices, bool directed = false)
  {
    adjList.resize(vertices);
    isDirected = directed;
  }

  void addEdge(int source, int destination)
  {
    adjList[source].push_back(destination);
    if (!isDirected)
    {
      adjList[destination].push_back(source);
    }
  }

  void printList()
  {
    for (int i = 0; i < adjList.size(); i++)
    {
      std::cout << i << ": ";
      for (int j = 0; j < adjList[i].size(); j++)
      {
        std::cout << adjList[i][j] << " -> ";
      }
      std::cout << "NULL" << std::endl;
    }
  }

  void bfs(int start) {
    std::queue<int> q;
    std::vector<bool> visited(adjList.size(), false);
    visited[start] = true;
    q.push(start);
    while (!q.empty()) {
      int current = q.front();
      q.pop();
      std::cout << current << " ";
      for (int i : adjList[current]) {
        if (!visited[i]) {
          visited[i] = true;
          q.push(i);
        }
      }
    }
    std::cout << std::endl;
  }

  void dfsHelp(std::vector<bool>& visited, int vertice) {
    if (visited[vertice]) return;
    visited[vertice] = true;
    std::cout << vertice << " ";
    for (int i : adjList[vertice]) {
      if (!visited[i]) {
        dfsHelp(visited, i);
      }
    }
  }
  void dfs(int start) {
    std::vector<bool> visited(adjList.size(), false);
    dfsHelp(visited, start);
    std::cout << std::endl;
  }
};

int main()
{
  int vertices = 3;

  // Undirected Graph Example
  adjacencyList undirectedGraph(vertices);
  undirectedGraph.addEdge(0, 1);
  undirectedGraph.addEdge(0, 2);
  undirectedGraph.addEdge(1, 2);
  std::cout << "Undirected Graph Adjacency List:" << std::endl;
  undirectedGraph.printList();
  std::cout << std::endl;

  // Directed Graph Example
  adjacencyList directedGraph(vertices, true);
  directedGraph.addEdge(1, 2);
  directedGraph.addEdge(1, 0);
  directedGraph.addEdge(2, 0);
  std::cout << "Directed Graph Adjacency List:" << std::endl;
  directedGraph.printList();

  // bfs
  undirectedGraph.bfs(0);
  directedGraph.bfs(0);
  //dfs
  undirectedGraph.dfs(0);
  directedGraph.dfs(0);
  return 0;
}
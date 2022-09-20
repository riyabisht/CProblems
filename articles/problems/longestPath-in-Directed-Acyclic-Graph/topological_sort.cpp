#include <climits>
#include <iostream>
#include <limits.h>
#include <stack>
#include <vector>

using namespace std;

class Graph {
public:
  vector<vector<pair<int, int>>> adj;
  stack<int> st;
  vector<int> visited;

  Graph(int vertex) {
    adj = vector<vector<pair<int, int>>>(vertex);
    visited = vector<int>(vertex, INT_MIN);
  }

  // longest Path in DAG
  void longestPath(int vertex, int source) {
    // find topological order
    for (int i = 0; i < vertex; i++) topological_order(i);

    // reinitialize
    for (int i = 0; i < visited.size(); i++) visited[i] = INT_MIN;
    visited[source] = 0;

    while (!st.empty()) {
      int u = st.top();
      st.pop();
      if (visited[u] != INT_MIN) {
        // source vertex
        for (auto i : adj[u]) {
          if (visited[i.first] < visited[u] + i.second)
            visited[i.first] = visited[u] + i.second;
        }
      }
    }
    for (auto i : visited) {
      (i == INT_MIN) ? cout << "INF " : cout << i << " ";
    }
  }

  // topological sort
  void topological_order(int u) {
    // if not visited
    if (visited[u] == INT_MIN) {
      visited[u] = 1;
      for (auto i : adj[u])
        topological_order(i.first);
      st.push(u);
    }
  }

  // add edge
  void addEdge(int u, int v, int w) { adj[u].push_back({v, w}); }

  // print topological order
  void printtopo() {
    while (!st.empty()) {
      cout << st.top();
      st.pop();
    }
    cout << endl;
  }

  // print graph
  void printGraph(int v) {
    cout << endl;
    for (int j = 0; j < v; j++) {
      cout << "u :" << j;
      for (auto i : adj[j]) {
        cout << "->" << i.first << "(" << i.second << ")";
      }
      cout << endl;
    }
  }
};

int main() {
  int vertex = 6;
  int source = 1;
  vector<vector<int>> edges = {
      {0, 1, 5},
      {0, 2, 3},
      {1, 2, 2},
      {1, 3, 6},
      {2, 3, 7},
      {2, 4, 4},
      {2, 5, 2},
      {3, 4, -1},
      {3, 5, 1},
      {4, 5, -2}};
  Graph g(vertex);
  for (auto edge : edges)
    g.addEdge(edge[0], edge[1], edge[2]);
  g.longestPath(vertex, source);
  return 0;
}

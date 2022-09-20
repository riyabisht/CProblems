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
    for (int i = 0; i < vertex; i++) {
      topological_order(i);
    }

    //reinitialise 
    for (int i = 0; i < visited.size(); i++)
      visited[i] = INT_MIN;
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
      (i == INT_MIN) ? cout << "INF" : cout << i << " ";
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
  void addEdge(int u, int v, int w) {
    adj[u].push_back({v, w});
  }

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

  int vertex = 0, edges = 0, source = 0;
  cout << "vertex edges source" << endl;
  cin >> vertex >> edges >> source;

  Graph g(vertex);

  for (int i = 1; i <= edges; i++) {
    int u, v, weight;
    cin >> u >> v >> weight;
    g.addEdge(u, v, weight);
  }

  g.longestPath(vertex, source);

  return 0;
}

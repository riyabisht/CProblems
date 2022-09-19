#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Job {
  char id;
  int deadLine, profit;
};

struct DisjointSet {
  int* parent;
  DisjointSet(int n) {
    parent = new int[n + 1];
    for (int i = 0; i <= n; i++) parent[i] = i;
  }
  int find(int s) {
    if (s == parent[s]) return s;
    return parent[s] = find(parent[s]);
  }
  void merge(int u, int v) { parent[v] = u; }
};

int printJobScheduling(vector<Job> arr) {
  int n = arr.size();
  sort(arr.begin(), arr.end(),
      [](const Job& a, const Job& b) { return a.profit > b.profit; });

  int maxDeadline = INT_MAX;
  for (auto i : arr) maxDeadline = max(maxDeadline, i.deadLine);
  DisjointSet ds(maxDeadline);

  for (int i = 0; i < n; i++) {
    int availableSlot = ds.find(arr[i].deadLine);
    if (availableSlot > 0) {
      ds.merge(ds.find(availableSlot - 1), availableSlot);
      cout << arr[i].id << " ";
    }
  }
}

int main() {
  vector<Job> arr = { {'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27}, {'d', 1, 25}, {'e', 3, 15}};
  printJobScheduling(arr);
  return 0;
}

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Job {
  char id;
  int dead;
  int profit;
};

void printJobScheduling(vector<Job>& arr) {
}

int main() {
  vector<Job> arr = {{'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27}, {'d', 1, 25}, {'e', 3, 15}};
  printJobScheduling(arr);
  return 0;
}

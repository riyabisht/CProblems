#include <iostream>
#include <vector>

using namespace std;

int rowWithMax1s(vector<vector<bool>> mat) {
  int rowIndex = -1;
  int maxCount = 0;
  for (int i = 0; i < mat.size(); i++) {
    int count = 0;
    for (int j = 0; j < mat[i].size(); j++) {
      if (mat[i][j] == 1) count++;
    }
    if (count > maxCount) {
      maxCount = count;
      rowIndex = i;
    }
  }
  return rowIndex;
}

int main() {
  vector<vector<bool>> mat = {
      {0, 0, 0, 1}, {0, 1, 1, 1}, {1, 1, 1, 1}, {0, 0, 0, 0}};
  cout << rowWithMax1s(mat);
  return 0;
}
#include <iostream>
#include <vector>

using namespace std;

int rowWithMax1s(vector<vector<bool>> mat) {
  int j, max_row_index = 0;
  j = mat[0].size() - 1;

  for (int i = 0; i < mat.size(); i++) {
    bool flag = false; // to check whether a row has more 1's than previous
    while (j >= 0 && mat[i][j] == 1) {
      j--;
      flag = true;
    }
    if (flag) max_row_index = i;
  }
  if (max_row_index == 0 && mat[0][mat[0].size() - 1] == 0) return -1;
  return max_row_index;
}

int main() {
  vector<vector<bool>> mat = {
      {0, 0, 0, 1}, {0, 1, 1, 1}, {1, 1, 1, 1}, {0, 0, 0, 0}};
  cout << rowWithMax1s(mat);
  return 0;
}
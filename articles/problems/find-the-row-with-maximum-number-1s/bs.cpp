#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<bool>& arr, int low, int high) {
  if (high >= low) {
    int mid = low + (high - low) / 2;
    if ((mid == 0 || arr[mid - 1] == 0) && arr[mid] == 1) return mid;
    else if (arr[mid] == 0)
      return binarySearch(arr, (mid + 1), high);
    else
      return binarySearch(arr, low, (mid - 1));
  }
  return -1;
}

int rowWithMax1s(vector<vector<bool>>& mat) {
  int max_row_index = 0, max = -1;
  int i, index;
  for (i = 0; i < mat.size(); i++) {
    // do binary search
    index = binarySearch(mat[i], 0, mat[i].size() - 1);
    if (index != -1 && mat[i].size() - index > max) {
      max = mat[i].size() - index;
      max_row_index = i;
    }
  }
  return max_row_index;
}

int main() {
  vector<vector<bool>> mat = {
      {0, 0, 0, 1}, {0, 1, 1, 1}, {1, 1, 1, 1}, {0, 0, 0, 0}};
  cout << rowWithMax1s(mat);
  return 0;
}
#include <iostream>
#include <vector>

using namespace std;

int optimal_weight(int W, vector<int> &w) {
  int size = w.size();
  int **weights = new int *[size + 1];

  for (int i = 0; i <= size; i++) {
    weights[i] = new int[W + 1];
  }

  for (int i = 0; i <= size; i++) {
    for (int j = 0; j <= W; j++) {      
        if (i == 0 || j == 0) {
          weights[i][j] = 0;
        }
        else if (w[i - 1] <= j) 
          weights[i][j] = max(w[i - 1] + weights[i - 1][j - w[i - 1]],  weights[i - 1][j]);
        else
          weights[i][j] = weights[i - 1][j];
    }
  }

  int result = weights[size][W];

  for (int i = 0; i < size; i++) {
    delete[] weights[i];
  }
  delete[] weights;

  return result;
}

int main() {
  int n, W;
  cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    cin >> w[i];
  }
  cout << optimal_weight(W, w) << '\n';
}

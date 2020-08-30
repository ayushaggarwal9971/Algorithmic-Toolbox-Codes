#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int lcs2(vector<int> &a, vector<int> &b, int m, int n) {
  int L[m + 1][n + 1];  
  int i, j;  
  for (i = 0; i <= m; i++) {
    for (j = 0; j <= n; j++) {
      if (i == 0 || j == 0)
        L[i][j] = 0;
      else if (a[i - 1] == b[j - 1])  
        L[i][j] = L[i - 1][j - 1] + 1;  
      else
        L[i][j] = max(L[i - 1][j], L[i][j - 1]);  
    }  
  }  
  return L[m][n];
}

int main() {
  size_t n;
  cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++) {
    cin >> a[i];
  }

  size_t m;
  cin >> m;
  vector<int> b(m);
  for (size_t i = 0; i < m; i++) {
    cin >> b[i];
  }

  cout << lcs2(a, b, a.size(), b.size()) << endl;
}

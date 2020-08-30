#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int partition2(vector<int> &a, int l, int r, int &i, int &j) {
  i = l - 1, j = r; 
  int p = l - 1, q = r; 
  int v = a[r]; 

  while (true) {
    while (a[++i] < v); 
    while (v < a[--j])
      if (j == l)
        break;
      if (i >= j) break;
      swap(a[i], a[j]);
      if (a[i] == v) { 
        p++; 
        swap(a[p], a[i]); 
      } 
      if (a[j] == v) { 
        q--; 
        swap(a[j], a[q]); 
      } 
  } 
  swap(a[i], a[r]); 
  j = i - 1; 

  for (int k = l; k < p; k++, j--) 
    swap(a[k], a[j]); 

  i = i + 1; 
  for (int k = r-1; k > q; k--, i++) 
    swap(a[i], a[k]);
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);

  int i, j;
  partition2(a, l, r, i, j);

  randomized_quick_sort(a, l, j);
  randomized_quick_sort(a, i, r);
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    cout << a[i] << ' ';
  }
}

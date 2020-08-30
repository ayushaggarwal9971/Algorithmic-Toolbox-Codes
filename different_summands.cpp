#include <iostream>
#include <vector>

using namespace std;

vector<int> optimal_summands(int n) {
  vector<int> summands;
  if(n <= 2) {
    summands.push_back(n);
    return summands;
  }
  n--;
  summands.push_back(1);
  int ele, x = 1, j = 0;
  while(n) {
    ele = summands[j] + x;
    if(n - ele == 0 || n - ele > ele) {
      summands.push_back(ele);
      n -= ele;
      x = 1;
      j++;
    }
    else x++;
  }
  return summands;
}

int main() {
  int n;
  cin >> n;
  vector<int> summands = optimal_summands(n);
  cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    cout << summands[i] << ' ';
  }
}

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std; 

int findMajority(vector<int> &a) { 
  unordered_map<int, int> m; 
  
  for(int i = 0; i < a.size(); i++) 
    m[a[i]]++; 
  
  for(auto i : m) { 
    if(i.second > a.size() / 2) { 
      return 1; 
      break; 
    } 
  } 
  return 0; 
} 

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    cin >> a[i];
  }
  cout << findMajority(a) << endl;
  return 0;
}


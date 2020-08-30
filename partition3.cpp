#include <iostream>
#include <vector>

using namespace std;

int PartitionPossible(vector<int> &A, int subSet[], bool visited[], int subSum, int curIdx, int limitIdx) {
  if (subSet[curIdx] == subSum) {
    if (curIdx == 1) 
      return true; 
    return PartitionPossible(A, subSet, visited, subSum, curIdx + 1, A.size() - 1);
  } 
  for (int i = limitIdx; i >= 0; i--) { 
    if (visited[i]) 
      continue; 
    int tmp = subSet[curIdx] + A[i];
    if (tmp <= subSum) { 
      visited[i] = true; 
      subSet[curIdx] += A[i]; 
      bool nxt = PartitionPossible(A, subSet, visited, subSum, curIdx, i - 1);
      visited[i] = false; 
      subSet[curIdx] -= A[i]; 
      if (nxt) 
        return 1; 
    } 
  } 
  return 0; 
} 


int partition3(vector<int> &A) {
  if(A.size() < 3) return 0;

  int sum = 0;
  for(int i = 0; i < A.size(); i++) {
  	sum += A[i];
  }
  if(sum % 3 != 0) return 0;

  int subSum = sum / 3;
  int subSet[3];
  bool visited[A.size()];

  for(int i = 0; i < 3; i++) {
  	subSet[i] = 0;
  }
  for (int i = 0; i < A.size(); i++) 
    visited[i] = false;

  subSet[0] = A[A.size() - 1];
  visited[A.size() - 1] = true;

  return PartitionPossible(A, subSet, visited, subSum, 0, A.size() - 1);
}

int main() {
  int n;
  cin >> n;
  vector<int> A(n);
  for (size_t i = 0; i < A.size(); ++i) {
    cin >> A[i];
  }
  cout << partition3(A) << '\n';
}

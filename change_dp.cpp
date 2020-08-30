#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const int INF = 1000000;

int get_change(int m) {
	int d[] = {1, 2, 4};
	vector<int> minNumCoins(m + 1);
	minNumCoins[0] = 0;
	int i, j;
	for(i = 1; i <= m; i++) {
		int minimum = INF;
		for(j = 0; j < 3; j++) {
			if(i >= d[j]) {
				minimum = min(minimum, 1 + minNumCoins[i - d[j]]);
			}
		}
		minNumCoins[i] = minimum;
	}
	return minNumCoins[m];
}

int main() {
  int m;
  cin >> m;
  cout << get_change(m) << '\n';
}

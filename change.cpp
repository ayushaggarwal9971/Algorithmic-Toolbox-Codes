#include <iostream>

using namespace std;

int get_change(int m) {
	int count = 0;
	while(m >= 10) {
  		m -= 10;
  		count++;
  	}
  	while(m >= 5) {
  		m -= 5;
  		count++;
  	}
  	while(m > 0) {
  		m -= 1;
  		count++;
  	}
  	return count;;
}

int main() {
  int m;
  cin >> m;
  cout << get_change(m) << '\n';
}

#include <iostream>

using namespace std;

unsigned long long fibonacci(int n) {
    unsigned long long first = 0, second = 1, temp = 0;
    if(n <= 1) return n;
    while(n - 1 > 0) {
    	temp = first + second;
    	first = second;
    	second = temp;
    	n--;
    }
    return temp;
}

int main() {
	int n;
    cin >> n;
    cout << endl;
    cout << fibonacci(n);
}
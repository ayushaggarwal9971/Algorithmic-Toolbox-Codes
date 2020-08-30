#include <iostream>

using namespace std;

int fibonacci_last_digit(int n) {
    unsigned long long first = 0, second = 1, temp = 0;
    if(n <= 1) return n;
    while(n - 1 > 0) {
        temp = first + second;
        first = second;
        second = temp;
        
        first %= 10;
        second %= 10;
        n--;
    }
    return second % 10;
}

int main() {
    int n;
    cin >> n;
    cout << endl;
    cout << fibonacci_last_digit(n) << endl;
}
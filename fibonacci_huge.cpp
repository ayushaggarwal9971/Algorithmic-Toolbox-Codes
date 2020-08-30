#include <iostream>

using namespace std;

long long get_pisano_period(long long m) {
    long long a = 0, b = 1, c = a + b;
    for (int i = 0; i < m * m; i++) {
        c = (a + b) % m;
        a = b;
        b = c;
        if (a == 0 && b == 1) return i + 1;
    }
    return 0;
}

unsigned long long get_fibonacci_huge_naive(long long n, long long m) {
    
    n = n % get_pisano_period(m);

    unsigned long long first = 0, second = 1, temp = 0;
    if(n <= 1) return n;
    while(n - 1 > 0) {
        temp = first + second;
        first = second;
        second = temp;
        n--;
        second %= m;
    }
    return temp % m;
}

int main() {
    long long n, m;
    cin >> n >> m;
    cout << get_fibonacci_huge_naive(n, m) << '\n';
}

#include <iostream>
#include <vector>

using namespace std;

double get_optimal_value(int capacity, vector<double> weights, vector<double> values) {
  double value = 0.0;
  int size = values.size(), count = 0;
  vector<double> v(size);

  for(int i = 0; i < size; i++) {
    v[i] = values[i] / weights[i];
  }

  while(capacity && count < size) {
    count++;
    int max = 0;

    for(int i = 1; i < size; i++) {
      if(v[i] > v[max]) max = i;
    }

    v[max] = 0.0;

    if(weights[max] >= capacity) {
      value += (values[max] / weights[max]) * capacity;
      capacity = 0;
    }
    else {
      value += values[max];
      capacity -= weights[max];
    }
  }
  return value;
}

int main() {
  int n;
  int capacity;
  cin >> n >> capacity;
  vector<double> values(n);
  vector<double> weights(n);
  for (int i = 0; i < n; i++) {
    cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  cout.precision(10);
  cout << optimal_value << endl;
  return 0;
}

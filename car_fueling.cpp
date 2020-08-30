#include <iostream>
#include <vector>

using namespace std;

int compute_min_refills(int dist, int tank, vector<int> & stops) {

    int refills = 0;
    int lastrefill = 0, currentrefill = 0;

    if((stops[currentrefill] + tank) >= dist) {
        return refills;
    }

    while (currentrefill < stops.size()) {
        lastrefill = currentrefill; 

        while ((currentrefill < stops.size()) && ((stops[currentrefill + 1] - stops[lastrefill]) <= tank)) 
            currentrefill++; 
        
        if (currentrefill == lastrefill)
            return -1;
        
        refills++;
        
        if((stops[currentrefill] + tank) >= dist)
            return refills;
    }

    return -1; 
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n + 2);
    stops[0] = 0;
    stops[n + 1] = d; 

    for (size_t i = 1; i < n + 1; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}

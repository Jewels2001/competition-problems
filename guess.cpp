#include <bits/stdc++.h>
using namespace std;

int l = 1;
int u = 1001;
int binarySearch(bool &x, int &start, int &lo, int &hi) {
    if(x == 1) {
        lo = start;
    } else {
        hi = start;
    }
    start = ((hi-lo)/2) + lo;
    return start;
}

int main() {
    int lo = 1;
    int hi = 1001;

    int start = 500;
    string response = "";
    int guess = 0;
    bool x = 0;
    while(response != "correct" || guess < 10) {
        cout << start << endl;
        cin >> response;
        if(response != "correct") {
            x = (response == "higher" ? 1 : 0);
            start = binarySearch(x, start, lo, hi);
        } else {
            return 0;
        }
        guess++;
    }

    //cout << flush;

}
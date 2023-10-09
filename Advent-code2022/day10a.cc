#include <bits/stdc++.h>
using namespace std;

vector<int> cyc;
void checkCycles(int X, int cycles) {
    cout << "X: " << X << " cycle# " << cycles << endl;
    if(cycles == 20 || cycles == 60 || cycles == 100 || cycles == 140 || cycles == 180 || cycles == 220) {
        cyc.push_back(X * cycles);
    }
}

int main() {
    int X = 1;
    int cycles = 1;
    string a;

    while(getline(cin, a)) {
        stringstream ss;
        ss << a;
        string temp;
        int v = 0;

        ss >> temp;
        if(temp == "addx") {
            cycles++;
            checkCycles(X, cycles);
            cycles++;
            ss >> v;
            X += v;
            checkCycles(X, cycles);
        } else if(temp == "noop") {
            cycles++;
            checkCycles(X, cycles);
        }
        //cout << "X: " << X << " cycle# " << cycles << endl;
    }

    int ans = 0;
    for(auto x : cyc) {
        cout << x << endl;
        ans += x;
    }
    cout << ans << endl;
}
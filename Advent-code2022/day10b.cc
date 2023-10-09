#include <bits/stdc++.h>
using namespace std;

vector<string> cyc(10, "");
void checkCycles(int X, int cycles) {
    cout << "X: " << X << " cycle# " << cycles << endl;
    int test = (cycles-1) % 40;
    int index = (cycles-1) / 40;
    cout << index << endl;
    if((test-1 >=0 && X == test-1) || X == test || X == test+1) {
        cyc[index] += "#";
    } else {
        cyc[index] += ".";
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

    //int ans = 0;//
    for(auto x : cyc) {
        cout << x << endl;
        
    }
    // cout << ans << endl;
}
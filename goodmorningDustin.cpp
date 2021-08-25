#include <bits/stdc++.h>
using namespace std;

int G[10][10] = {{1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                 {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                 {1, 0, 1, 1, 0, 1, 1, 0, 1, 1},
                 {0, 0, 0, 1, 0, 0, 1, 0, 0, 1},
                 {1, 0, 0, 0, 1, 1, 1, 1, 1, 1},
                 {1, 0, 0, 0, 0, 1, 1, 0, 1, 1},
                 {0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
                 {1, 0, 0, 0, 0, 0, 0, 1, 1, 1},
                 {1, 0, 0, 0, 0, 0, 0, 0, 1, 1},
                 {0, 0, 0, 0, 0, 0, 0, 0, 0, 1}};

set<int> s;

void f(string str, int x, int d) {
    if(d == 3)
        s.insert(stoi(str + to_string(x)));
    else {
        for(int i=0; i<10; i++) {
            if(G[x][i]) {
                s.insert(stoi(str + to_string(x)));
                f(str + to_string(x), i, d+1);
            }
        }
    }
}

int main() {
    for(int i=0; i<10; i++) {
        f("", i, 1);
    }

    // for(auto i:s)
    //     cout<<i<<endl;

    int T; cin>>T;
    while(T--) {
        int k; cin>>k;
        int closest = 0;
        int dif = INT_MAX;

        for(auto x:s) {
            if(abs(x-k) < dif) {
                closest = x;
                dif = abs(x-k);
            }
        }
        cout<<closest<<endl;
    }
}
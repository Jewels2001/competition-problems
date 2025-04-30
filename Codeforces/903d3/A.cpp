#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        string x, s;
        int n, m;
        cin >> n >> m;
        cin >> x;
        cin >> s;
        int count = 0;
        while(x.length() < s.length()) {
            x+=x;
            count++;
        }
        while(x.find(s) == string::npos && x.length() < 1000) {
            x += x; 
            count++;
        }
        if(x.find(s) != string::npos) {
            cout << count << endl;
        } else {
            cout << -1 << endl;
        }
    }
}
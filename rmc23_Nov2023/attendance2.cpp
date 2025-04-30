#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string last = "Present!";
    vector<string> absent;
    for(int i=0; i<n; i++) {
        string callout;
        cin >> callout;
        if(last != "Present!" && callout != "Present!") {
            absent.push_back(last);
        }
        last = callout;
    }
    if(last != "Present!") {
        absent.push_back(last);
    }

    if(absent.size() == 0) {
        cout << "No Absences" << endl;
    } else {
        for(auto a : absent) {
            cout << a << endl;
        }
    }
}
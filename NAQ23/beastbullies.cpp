#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> animals(n);
    for(int i=0; i<n; i++) {
        cin >> animals[i];
    }
    sort(rbegin(animals), rend(animals));
}
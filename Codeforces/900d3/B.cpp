#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> ans;
    int a1 = 1; ans.push_back(a1);
    int a2 = 3; ans.push_back(a2);
    int a3 = 6; ans.push_back(a3);
    int curr=a3;
    for(int i=3; i<20000; i++) {
        ans.push_back(curr);
        a1 = ans[i-2];
        a2 = ans[i-1];
        a3 = ans[i];
        if((a1 + a2) % (3*a3)) {
            continue;
        } else{
            a3++;
        }
    }


    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

    }
}
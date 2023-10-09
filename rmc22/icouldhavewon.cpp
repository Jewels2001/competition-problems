#include<bits/stdc++.h>
using namespace std;

int main() {
    string score;
    cin >> score;
    int ans = 0;
    vector<int> ans2;

    int max_k = score.length();
    int k = 1;
    while(k <= max_k) {
        int alice = 0;
        int bob = 0;

        int bob_temp = 0;
        int alice_temp = 0;
        for(int i=0; i<score.length(); i++) {
            if(score[i] == 'A') {
                alice_temp++;
            } else {
                bob_temp++;
            }
            if(alice_temp == k) {
                alice++;
                bob_temp = 0;
                alice_temp = 0;
            } else if(bob_temp == k) {
                bob++;
                alice_temp = 0;
                bob_temp = 0;
            }
        }
        if(alice > bob) {
            ans++;
            ans2.push_back(k);
        }
        k++;
    }
    cout << ans << endl;
    if(ans != 0) {
        for(auto x : ans2) {
            cout << x << " ";
        }
    }

}
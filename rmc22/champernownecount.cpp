#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ll n, k;
    cin >> n >> k;
    if(k == 1) {
        cout << n << endl;
        return 0;
    }
    string s = "1";
    ll ans = 0;
    ll temp = 1;
    for(int i=2; i<=n; i++) {
        s += to_string(i);
        //cout << "S: " << s << endl;
        temp = stoll(s);
        //cout << "N:" << temp << endl;
        if(temp % k == 0) {
            ans++;
        }
        temp %= k;
        s = to_string(temp);
        //cout << "N:" << n << endl;
    }
    cout << ans << endl;
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> primeFactors(int p) {
    vector<ll> temp;
    while(!(p % 2)) {
        temp.push_back(2);
        p = p / 2;
    } 
    for(ll i=3; i*i <= p; i = i + 2) {
        while(!(p % i)) {
            temp.push_back(i);
            p = p / i;
        }
    }
    if(p > 2) {
        temp.push_back(p);
        p = p/p;
    } 
return temp;
}


int main() {
    vector<vector<ll>> sum;

    int t;
    cin >> t;
    int cases = 1;
    while(t--) {
        vector<ll> a;
        ll p;
        cin >> p;
        cout << "Case #" << cases++ << ":";

        vector<ll> primes = primeFactors(p);
        int sum = 0;
        for(int i=0; i< primes.size(); i++) {
            sum += primes[i];
        }
        if(sum > 41 || a.size() > 100 || (41-sum)+a.size()>100 ) {
            cout << " -1" << endl;
            continue;
        }
        for(auto x : primes) {
            a.push_back(x);
        }
        while(sum != 41) {
            a.push_back(1);
            sum++;
        }
       
        cout << " " << a.size();
        
        for(auto ans : a) {
            cout << " " << ans;
        }
        cout << endl;
    }
}
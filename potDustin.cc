#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin>>n;
    long long ans = 0;
    for(int i=0; i<n; i++) {
        int p; cin>>p;
        int base = p/10;
        int power = p%10;
        ans += pow(base, power);
    }
    cout<<ans<<endl;
}

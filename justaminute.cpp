#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    double m = 0, s = 0;
    for(int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        m += a;
        s += b;
    }
    m *= 60;
    double ans = s/m;
    if(ans > 1.0) {
        cout << fixed << setprecision(10) << ans << endl;
    } else {
        cout << "measurement error" << endl;
    }
}
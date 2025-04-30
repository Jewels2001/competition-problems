#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<bool>> seconds(n, vector<bool>(86400, 0));
    for(int i=0; i<n; i++) {
        int m;
        cin >> m;
        for(int j=0; j<m; j++) {
            int l, r;
            cin >> l >> r;
            for(int x=l; x<=r; x++) {
                seconds[i][x] = 1;
            }

        }
    }
    int curCountPics = 0;
    int curSecs = 0;
    for(int i=0; i<86400; i++) {
        int avail = 0;
        for(int j=0; j<n; j++) {
            if(seconds[j][i]) {
                avail++;
            }
        }
        if(avail > curCountPics) {
            curCountPics = avail;
            curSecs = 1;
        } else if(avail == curCountPics) {
            curSecs++;
        }
    }
    cout << curCountPics << endl << curSecs << endl;
}
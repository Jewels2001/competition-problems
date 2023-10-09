#include <bits/stdc++.h>
using namespace std;

bool onePt(int i, int j) {
    if(i == 0 || i == 9 || j == 0 || j == 9) {
        return true;
    }
    return false;
}

bool twoPt(int i, int j) {
    if(i == 1 || i == 8 || j == 1 || j == 8) {
        return true;
    }
    return false;
}

bool threePt(int i, int j) {
    if(i == 2 || i == 7 || j == 2 || j == 7) {
        return true;
    }
    return false;
}

bool fourPt(int i, int j) {
    if(i == 3 || i == 6 || j == 3 || j == 6) {
        return true;
    }
    return false;
}

bool fivePt(int i, int j) {
    if(i == 4 || i == 5 || j == 4 || j == 5) {
        return true;
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int ans = 0;
        for(int i=0; i<10;i++) {
            for(int j=0; j<10;j++) {
                char temp;
                cin >> temp;
                if(temp == 'X') {
                    if(onePt(i, j)) {
                        ans += 1;
                    } else if(twoPt(i, j)) {
                        ans += 2;
                    } else if(threePt(i, j)) {
                        ans += 3;
                    } else if(fourPt(i, j)) {
                        ans += 4;
                    } else if(fivePt(i, j)) {
                        ans += 5;
                    }
                }
            }
        }
        cout << ans << endl;
    }
}
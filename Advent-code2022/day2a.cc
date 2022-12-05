#include <bits/stdc++.h>
using namespace std;

// 0 loss, 3 draw, 6 won
int checkWin(string a, string b) {
    if (a == "A") {
        if(b == "X") {
            return 3;
        } else if(b == "Y") {
            return 6;
        } else if(b == "Z") {
            return 0;
        }
    } else if(a == "B") {
        if(b == "X") {
            return 0;
        } else if(b == "Y") {
            return 3;
        } else if(b == "Z") {
            return 6;
        }
    } else if(a == "C") {
        if(b == "X") {
            return 6;
        } else if(b == "Y") {
            return 0;
        } else if(b == "Z") {
            return 3;
        }
    }
    return 0;
}


int main() {
    string a, b;
    int total = 0;
    while(cin >> a >> b) {
        int scoreA = -1;
        int scoreB = -1;
        if(b == "X") {
            scoreB = 1;
        } else if(b == "Y") {
            scoreB = 2;
        } else if(b == "Z") {
            scoreB = 3;
        }
        scoreB += checkWin(a, b);
        total += scoreB;
    }
    cout << total << endl;
}
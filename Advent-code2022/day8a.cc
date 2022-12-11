#include <bits/stdc++.h>
using namespace std;

vector<string> yo;
int r = 0, c = 0;


//check for yo[0][0]= yo[0][1], yo[1][0], yo[1][1]

//check for yo[1][1],yo[] 

bool inBounds(int i, int j) {
    if(i < 0 || i >= c) {
        return false;
    }
    if(j < 0 || j >= r) {
        return false;
    }
    return true;
}

bool checkUp(int i, int j, int curr) {
    cout << "up" << endl;
    if(inBounds(i-1, j) && ((yo[i-1][j] - '0') < curr)) {
        cout <<"here" << endl;
        return checkUp(i-1, j, curr);
    } else if(!inBounds(i-1, j) && ((yo[i][j] - '0') < curr)) {
        cout <<"here1" << endl;
        return true;
    }
    cout <<"here2" << endl;
    return false;
}
bool checkLeft(int i, int j, int curr) {
    cout << "down" << endl;
    if(inBounds(i, j-1) && ((yo[i][j-1] - '0') < curr)) {
        return checkLeft(i, j-1, curr);
    } else if(!inBounds(i, j-1) && ((yo[i][j] - '0') < curr)) {
        return true;
    }
    return false;
}
bool checkDown(int i, int j, int curr) {
    cout << "down" << endl;
    if(inBounds(i+1, j) && ((yo[i+1][j] - '0') < curr)) {
        return checkDown(i+1, j, curr);
    } else if(!inBounds(i+1, j) && ((yo[i][j] - '0') < curr)) {
        return true;
    }
    return false;
}
bool checkRight(int i, int j, int curr) {
    cout << "right" << endl;
    if(inBounds(i, j+1) && ((yo[i][j+1] - '0') < curr)) {
        return checkRight(i, j+1, curr);
    } else if(!inBounds(i, j+1) && ((yo[i][j] - '0') < curr)) {
        return true;
    }
    return false;
}


int main() {
    string a;
    int count = 0;
    while(getline(cin, a)) {
        yo.push_back(a);
    }
    r = yo[0].length();
    c = yo.size();

    for(int i=0; i<c; i++) {
        for(int j=0; j<r; j++) {
            cout << yo[i][j] << endl;
            int curr = yo[i][j] - '0';
            cout << curr << endl;
            //check if on edge -- visible
            if(!inBounds(i-1, j) || !inBounds(i, j-1) || !inBounds(i+1, j) || !inBounds(i, j+1)) {
                count++;
                continue;
            }
            //check sides
            // if(i <= c/2) {
            //     if(j <= r/2) {
            //         if(checkUp(i, j, curr) && checkLeft(i,)) {
            //             count++;
            //         }
            //     } else {
            //         if(check)
            //     }
                
            // }
            if(checkUp(i, j, curr) || checkLeft(i, j, curr) || checkRight(i, j, curr) || checkDown(i, j, curr)) {
                count++;
            }
        }
    }

    cout << "COUNT: " << count << endl;
}
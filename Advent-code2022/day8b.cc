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

int checkUp(int i, int j, int curr) {
    if(inBounds(i-1, j) && ((yo[i-1][j] - '0') < curr)) {
        return checkUp(i-1, j, curr) + 1;
    } else if(!inBounds(i-1, j)) {
        return 0;
    }
    return 1;
}
int checkLeft(int i, int j, int curr) {
    if(inBounds(i, j-1) && ((yo[i][j-1] - '0') < curr)) {
        return checkLeft(i, j-1, curr) + 1;
    } else if(!inBounds(i, j-1)) {
        return 0;
    }
    return 1;
}
int checkDown(int i, int j, int curr) {
    if(inBounds(i+1, j) && ((yo[i+1][j] - '0') < curr)) {
        return checkDown(i+1, j, curr) + 1;
    } else if(!inBounds(i+1, j)) {
        return 0;
    }
    return 1;
}
int checkRight(int i, int j, int curr) {
    if(inBounds(i, j+1) && ((yo[i][j+1] - '0') < curr)) {
        return checkRight(i, j+1, curr) + 1;
    } else if(!inBounds(i, j+1)) {
        return 0;
    }
    return 1;
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
            int up = checkUp(i, j, curr);
            int d = checkDown(i, j, curr);
            int right = checkRight(i, j, curr);
            int left = checkLeft(i, j, curr);
            cout << "THIS TREE:" << (checkUp(i, j, curr) * checkLeft(i, j, curr) * checkRight(i, j, curr) * checkDown(i, j, curr)) << endl;
            cout << "UP" << up << endl;
            cout << "DOWN" << d << endl;
            cout << "R" << right << endl;
            cout << "L" << left << endl;
            count = max(count, checkUp(i, j, curr) * checkLeft(i, j, curr) * checkRight(i, j, curr) * checkDown(i, j, curr));
            
        }
    }

    cout << "COUNT: " << count << endl;
}
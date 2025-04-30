#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<char>> attributes(n, vector<char>(m, '.'));
    vector<int> responses(n, 0);
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> attributes[i][j];
        }
    }
    for(int i=0; i<q; i++) {
        int a;
        char ans;
        cin >> a >> ans;
        for(int x=0; x<n; x++) {
            if(attributes[x][a-1] == ans) {
                responses[x]++;
            }
        }
    }
    int character = 0;
    int total = -1;
    int numChars = 0;
    for(int i=0; i<n; i++) {
        if(responses[i] > total) {
            total = responses[i];
            character = i+1;
            numChars = 1;
        } else if(responses[i] == total) {
            numChars++;
        }
    }
    if(numChars > 1) {
        cout << "ambiguous" << endl << numChars << endl; 
    } else if(total == -1) {
        cout << "ambiguous" << endl << n << endl;
    } else {
        cout << "unique" << endl << character << endl;
    }


}
#include <bits/stdc++.h>
using namespace std;

    // up, right, left, down
    int dr[4] = {-1, 0, 0, 1};
    int dc[4] = {0, 1, -1, 0};

bool outOfBounds(int r, int c, int i, int j) {
    if(i < 0 || j < 0 || i >= r || j >= c) {
        return true;
    }
    return false;
}

// bfs 
int bfs(const vector<vector<char>>& board, vector<vector<int>>& visited, pair<int,int> p, int r, int c) {
    queue<pair<int, int>> q;
    q.push(p);
    //bfs for each 
    int num = 0;
    visited[p.first][p.second] = 1;
    while(!q.empty()) {
        pair<int,int> cur = q.front(); q.pop();
        visited[cur.first][cur.second] = 1;
        for(int d=0; d<4; d++) {
            int i = cur.first+dr[d];
            int j = cur.second+dc[d];
            if(!outOfBounds(r,c,i,j)) {

                if(board[i][j] == 'W' && visited[i][j] == -1) {
                    q.push(make_pair(i,j));
                } else if(board[i][j] == '.' && visited[i][j] == -1) {
                    visited[i][j] = 1;
                    num++;
                }
            } 
        }
    }
    return num;
}


int main() {

    int t;
    cin >> t;
    int cases = 1;
    while(t--) {
        cout << "Case #" << cases++ << ": ";
        int r, c;
        cin >> r >> c;

        int sr = -1; int sc = -1;

        vector<vector<char>> board(r, vector<char>(c));
        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                cin >> board[i][j]; 
                if(board[i][j] == 'W' && sr == -1) {
                    sr = i; sc = j;
                }     
            }
        }

        // No whites in graph for some reason
        if(sr == -1) {
            cout << "NO" << endl;
            continue;
        }

        //step 1: identify white with empty spot
        //step 2: follow white to check if other whites in group have 
        // no empty spot (only 1 empty spot beside group)

        vector<vector<int>> visited(r, vector<int>(c, -1));
        bool done = false;

        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                if(board[i][j] == 'W' && visited[i][j] == -1) {
                    int num = bfs(board, visited, make_pair(i, j), r, c);
                    if(num == 1) {
                        cout << "YES" << endl;
                        done = true;
                        break;
                    }
                    // reset visited
                    for(int i1=0; i1<r; i1++) {
                        for(int j1=0; j1<c; j1++) {
                            if(board[i1][j1] == '.') {
                                visited[i1][j1] = -1;
                            }
                        }
                    }
                }
            }
            if(done) { 
                break;
            }
        }
        if(!done) {
            cout << "NO" << endl;
        }
        
    }
}
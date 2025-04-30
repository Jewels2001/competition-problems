// not done
#include <bits/stdc++.h>
using namespace std;

// up, down, left, right
int dx = [1, -1, 0, 0];
int dy = [0, 0, -1, 1];

bool bounds(int i, int j) {
    bool in = true;
    

    return in;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> maze(n, vector<char>(m));
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> maze[i][j];
        }
    }

    vector<vector<int>> visited(n, vector<int>(m, 0));
    int doors = 0;

    // bfs through the maze looking for more doors
    // if two or more doors connect, only need one of those.
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(!(i==0 || i==n-1) && (j>0 && j<M-1)) continue;
            if(maze[i][j] == 'X') continue;
            doors++;
            //bfs
            queue<pair<int, int>> q;
            q.push(make_pair(i, j));
            visited[i][j] = 1;
            while(!q.empty()) {
                pair<int, int> temp = q.front; q.pop;
                for(int k=0; k<4; k++) {
                    if()
                }
            }
        }
    }
}
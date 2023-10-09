#include <bits/stdc++.h>
using namespace std;

// struct Edge {
//     int weight;
// }

typedef pair<int, int> pii;

//edge num, weight
vector<vector<pii>> graph;
int R = 0;
int C = 0;

// left, up, right, down
int dx [4] = {-1, 0, 1, 0};
int dy [4] = {0, 1, 0, -1};

bool checkBounds(int r1, int c1) {
    if(r1 < 0 || r1 >= R) {
        return false;25
    }
    if(c1 < 0 || c1 >= C) {
        return false;
    }
    return true;
}

int calcSpot(int x, int y) {
    return (x*C) + y;
}

int minDistance(vector<int> dist, vector<bool> seen) {
    int min = INT_MAX, min_index;
    for(int v=0; v<R*C; v++) {
        if(seen[v] == false && dist[v] <= min) {
            min = dist[v], min_index = v;
        }
    }
    return min_index;

}

void printSol(vector<int> dist) {
    cout << "Dist from Src" << endl;
    for(int i=0; i< R*C; i++) {
        cout << i << ":  " << dist[i] << endl; 
    }
}


void D(int src, int end) {
    vector<int> dist(R*C);
    vector<bool> seen(R*C);

    // step 1, initialize dists from src to others as inf
    for(int i=0; i<C*R; i++) {
        dist[i] = INT_MAX;
        seen[i] = false;
    }
    dist[src] = 0;

    // find shortest path for all verticies
    for(int count =0; count < (C*R)-1; count++) {
        // pick shortest distance of not processed
        int u = minDistance(dist, seen);
        // mark visited
        seen[u] = true;
        // update dist values for adjacent
        // should v be 4 or R*C ?
        for(int v=0; v<graph[u].size(); v++) {
            if(!seen[v] && dist[u] != INT_MAX && (dist[u] + graph[u][v].second) < dist[v]) {
                dist[v] = dist[u] + graph[u][v].second;
            }
        }
    }
    printSol(dist);
    cout << "END is vertex " << end << endl;

}



int main() {

    int start_r = 0;
    int start_c = 0;
    int end_r = 0;
    int end_c = 0;
    string a;
    // create graph
    vector<string> woo;
    while(getline(cin, a)) {
        woo.push_back(a);
    }
    R = woo.size();
    C = woo[0].length();
    graph.resize(R*C);
    for(int i=0; i<R; i++) {
        // int currNode is i
        for(int j=0; j<C; j++) {
            char current = woo[i][j];
            int weight = -1;
            if(woo[i][j] == 'S') {
                start_r = i;
                start_c = j;
                current = 'a'; 
            }
            if(woo[i][j] == 'E') {
                end_r = i;
                end_c = j;
                current = 'z';
            }
            for(int k=0; k<4; k++) {
                int nX = i+dy[k];
                int nY = j+dx[k];
                if(checkBounds(nX, nY)) {
                    if(abs(woo[nX][nY] - current) <= 1) {
                        pii lol;
                        lol.first = j;
                        lol.second = abs(woo[nX][nY] - current);
                        cout << abs(woo[nX][nY] - current) << endl;
                        graph[i].push_back(lol);
                    }
                }
            }

        }
    }

    // go through graph
    D(calcSpot(start_r, start_c), calcSpot(end_r, end_c));

}
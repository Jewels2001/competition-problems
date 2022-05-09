/*
By: Julie Wojtiw-Quo
Used bipartite matching algorithm to match the possible cards in the hand (set 1,
size of hand = n) with all possible cards (set 2, size n*2). If maximum
bipartite matching is equal to the number of cards in the hand, then they can all
be played on the first turn.
*/

//bipartitie matching to check whether subset played is also all cards

#include <bits/stdc++.h>
using namespace std;
// Unweighted Bipartite Matching (Undirected Only) -- O(m*sqrt(n))
//  -- Your match is stored in "mate". (mate == -1 if there is no match)
//  -- adj is an adjacency list that indexes the other set
//         Ex: U[0].adj[0] == x means there is an edge from U[0] to V[x]

struct Node{
  vector<int> adj; int mate,pred;
}; // Ignore "pred" -- For internal use.

void add_edge(Node U[],int u_node,Node V[],int v_node){
  U[u_node].adj.push_back(v_node);
  V[v_node].adj.push_back(u_node);
}

// u is the number of elements in U
// v is the number of elements in V
int match(Node U[],int u,Node V[],int v){
  for(int i=0;i<u;i++) U[i].mate = -1;
  for(int i=0;i<v;i++) V[i].mate = -1;

  int numMatches = 0;
  while(true){
    queue<int> q1,q2;
    for(int i=0;i<u;i++) if(U[i].mate == -1) q1.push(i);
    for(int i=0;i<u;i++) U[i].pred = -1;
    for(int i=0;i<v;i++) V[i].pred = -1;

    while(!q1.empty()){
      int x = q1.front(); q1.pop();
      for(int i=0;i<U[x].adj.size();i++){ int w = U[x].adj[i];
    if(V[w].pred != -1) continue;
    if(V[w].mate == -1) V[w].pred = x , q2.push(w);
    else if(V[w].mate != x && U[V[w].mate].pred == -1)
      V[w].pred = x , U[V[w].mate].pred = w , q1.push(V[w].mate);
      }
    }

    if(q2.empty()) break;
    while(!q2.empty()){
      Node* W = V; int i,x = q2.front(); q2.pop();
      for(i = x;i >= 0;W=(W == U ? V : U)) i = W[i].pred;
      if(i == -2) continue; numMatches++;
      for(i = x;i >= 0;){
    int p = V[i].pred;  V[i].pred = -2;  V[i].mate = p;
    U[p].mate = i;      i = U[p].pred;   U[p].pred = -2;
      }
    }
  }
  return numMatches;
}


int main() {
  int cases;
  cin >> cases;
  while(cases--) {
    int cards;
    cin >> cards;
    Node u[50001], v[100002];
    for(int i=0;i<cards;i++) {
      int x, y;
      cin >> x >> y;
      x = x-1;
      y = y-1;
      add_edge(u, i, v, x);
      add_edge(u, i, v, y);
    }

    int ans = match(u,cards,v,2*cards);

    if(ans == cards) {
      cout << "possible" << endl;
    } else {
      cout << "impossible" << endl;
    }
  }
  return 0;
}

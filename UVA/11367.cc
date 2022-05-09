/*
By: Julie Wojtiw-Quo
Single source shortest path using dijkstras (used dijkstra_spare.cc from code
library bc each node only has a couple of connections - minimum 2, at most around
100 where there are 101000 nodes). The dijkstra.cc is too slow. Set up nodes so
that each city has 100 nodes for fuel 0-100, for a total num nodes = 101*n cities.
Created getID functions for returning the node id, location id and fuel id.
Connected every possible fuel amount for one city together (with the price as
weights) and then connected cities by connecting current fuel and loc to the
new city location with the fuel used subtracted. Then ran dijkstra's single src
shortest path for every query, with an added check before pushing neighbours
that stops if the fuel amount is abovethe fuel capacity.
*/
#include <bits/stdc++.h>
using namespace std;

//keep track of location and fuel level, index nodes
//if fuel is 0-100, then
// index = loc * 101 + fuel
// loc = index / 101
// fuel = index % 101
int getNodeID(int loc, int fuel) {
 return loc*101 + fuel;
}

int getLoc(int id) {
  return id/101;
}

int getFuel(int id) {
  return id % 101;
}
/*
 * Dijkstra's Algorithm for sparse graphs
 *
 * Author: Howard Cheng
 *
 * Given a weight matrix representing a graph and a source vertex, this
 * algorithm computes the shortest distance, as well as path, to each
 * of the other vertices.  The paths are represented by an inverted list,
 * such that if v preceeds immediately before w in a path from the
 * source to vertex w, then the path P[w] is v.  The distances from
 * the source to v is given in D[v] (-1 if not connected).
 *
 * Call get_path to recover the path.
 *
 * Note: Dijkstra's algorithm only works if all weight edges are
 *       non-negative.
 *
 * This version works well if the graph is not dense.  The complexity
 * is O((n + m) log (n + m)) where n is the number of vertices and
 * m is the number of edges.
 *
 */

struct Edge {
  int to;
  int weight;       // can be double or other numeric type
  Edge(int t, int w)
    : to(t), weight(w) { }
};

typedef vector<Edge>::iterator EdgeIter;

struct Graph {
  vector<Edge> *nbr;
  int num_nodes;
  Graph(int n)
    : num_nodes(n)
  {
    nbr = new vector<Edge>[num_nodes];
  }

  ~Graph()
  {
    delete[] nbr;
  }

  // note: There is no check on duplicate edge, so it is possible to
  // add multiple edges between two vertices
  //
  // If this is an undirected graph, be sure to add an edge both
  // ways
  void add_edge(int u, int v, int weight)
  {
    nbr[u].push_back(Edge(v, weight));
  }
};

/* assume that D and P have been allocated */
void dijkstra(const Graph &G, int src, vector<int> &D, vector<int> &P, int cap)
{
  typedef pair<int,int> pii;

  int n = G.num_nodes;
  vector<bool> used(n, false);
  priority_queue<pii, vector<pii>,  greater<pii> > fringe;

  D.resize(n);
  P.resize(n);
  fill(D.begin(), D.end(), -1);
  fill(P.begin(), P.end(), -1);

  D[src] = 0;
  fringe.push(make_pair(D[src], src));

  while (!fringe.empty()) {
    pii next = fringe.top();
    fringe.pop();
    int u = next.second;
    if (used[u]) continue;
    used[u] = true;

    for (EdgeIter it = G.nbr[u].begin(); it != G.nbr[u].end(); ++it) {
      int v = it->to;
      int weight = it->weight + next.first;
      if (used[v]) continue;
			//added line:
			if (getFuel(v) > cap) continue;
      if (D[v] == -1 || weight < D[v]) {
	D[v] = weight;
	P[v] = u;
	fringe.push(make_pair(D[v], v));
      }
    }
  }
}

int get_path(int v, const vector<int> &P, vector<int> &path)
{
  path.clear();
  path.push_back(v);
  while (P[v] != -1) {
    v = P[v];
    path.push_back(v);
  }
  reverse(path.begin(), path.end());
  return path.size();
}



// Nodes: each location has all different fuel levels
// Weight: to move one fuel level is cost to fill up one unit of gas
//directed, if takes 0-2->1, then (0,100)->(1,98) and cannot drive if less than 2.
//Also draw edges other way, (1,100)->(2,98), all weight 0 (don't need to pay)

//nodes: #cities * 101 (max 101,000 nodes)
vector<int> fuelPrices;
int n, m;

// connect/build graph
void connectGraph(Graph &G) {
	// connect fuel prices of one city, for every city
	for(int c=0; c<n; c++) {
		for(int i=0; i<100; i++) {
				int id = getNodeID(c, i);
				G.add_edge(id, id+1, fuelPrices[c]);
		}
	}
	// connect cities together
	int u, v, d;
	for(int i=0; i<m; i++) {
		cin >> u >> v >> d;
		// starting at lowest fuel possible (d value)
		// and goes up to max
		int uID = getNodeID(u, d);
		int uStop = getNodeID(u, 100);
		int vID = getNodeID(v, d);
		int vStop = getNodeID(v, 100);
		while(uID < uStop && vID < vStop) {
			G.add_edge(uID, vID-d, 0);
			G.add_edge(vID, uID-d, 0);
			uID++;
			vID++;
		}

	}
}

//build stack of nodes for each city, run dijkstras
int main() {
  cin >> n >> m;
	int nodes = n*101;
	Graph G(nodes);
	fuelPrices.resize(n);
	for(int i=0; i<n; i++) {
		cin >> fuelPrices[i];
	}
	connectGraph(G);

	  /* do queries */
	int q;
	cin >> q;
	while(q--) {
		int c, s, e;
		cin >> c >> s >> e;
		//gas tank starts empty
		int src = getNodeID(s, 0);
		vector<int> D, P, path;
 		dijkstra(G, src, D, P, c);

		int minCost = INT_MAX;
		for(int i=0; i<101; i++) {
			int end = getNodeID(e, i);
			if(D[end] != -1) {
				minCost = min(minCost, D[end]);
			}
		}
		if(minCost == INT_MAX) {
			cout << "impossible" << endl;
		} else {
			cout << minCost << endl;
		}
	}
  return 0;
}

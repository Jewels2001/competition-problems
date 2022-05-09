/*
By: Julie Wojtiw-Quo
Used networkflow.cc from code library, stored all the input data using maps and
a struct, and then built a directed graph such that the source is connected to
the clubs, the clubs are connected to people, people are connected to parties
and parties are connected to the sink. There is no direct relationship between
the clubs and parties. The output flow should be num of clubs, else impossible.
We set flow from parties to sink as (num clubs-1)/2 for the constraints
*/

#include <bits/stdc++.h>
using namespace std;

/*
 * Network Flow
 *
 * Author: Howard Cheng
 *
 * The routine network_flow() finds the maximum flow that can be
 * pushed from the source (s) to the sink (t) in a flow network
 * (i.e. directed graph with capacities on the edges).  The maximum
 * flow is returned.  Note that the graph is modified.  If you wish to
 * recover the flow on an edge, it is in the "flow" field, as long as
 * is_real is set to true.
 *
 * Note: if you have an undirected network. simply call add_edge twice
 * with an edge in both directions (same capacity).  Note that 4 edges
 * will be added (2 real edges and 2 residual edges).  To discover the
 * actual flow between two vertices u and v, add up the flow of all
 * real edges from u to v and subtract all the flow of real edges from
 * v to u.  (In fact, for a residual edge the flow is always 0 in this
 * implementation.)
 *
 * This code can also be used for bipartite matching by setting up an
 * appropriate flow network.
 *
 * The code here assumes an adjacency list representation since most
 * problems requiring network flow have sparse graphs.
 *
 * This is the basic augmenting path algorithm and it is not the most
 * efficient.  But it should be good enough for most programming contest
 * problems.  The complexity is O(f m) where f is the size of the flow
 * and m is the number of edges.  This is good if you know that f
 * is small, but can be exponential if f is large.
 *
 */


struct Edge;
typedef list<Edge>::iterator EdgeIter;

struct Edge {
  int to;
  int cap;
  int flow;
  bool is_real;
  EdgeIter partner;

  Edge(int t, int c, bool real = true)
    : to(t), cap(c), flow(0), is_real(real)
  {};

  int residual() const
  {
    return cap - flow;
  }
};

struct Graph {
  list<Edge> *nbr;
  int num_nodes;
  Graph(int n)
    : num_nodes(n)
  {
    nbr = new list<Edge>[num_nodes];
  }

  ~Graph()
  {
    delete[] nbr;
  }

  // note: this routine adds an edge to the graph with the specified capacity,
  // as well as a residual edge.  There is no check on duplicate edge, so it
  // is possible to add multiple edges (and residual edges) between two
  // vertices
  void add_edge(int u, int v, int cap)
  {
    nbr[u].push_front(Edge(v, cap));
    nbr[v].push_front(Edge(u, 0, false));
    nbr[v].begin()->partner = nbr[u].begin();
    nbr[u].begin()->partner = nbr[v].begin();
  }
};

void push_path(Graph &G, int s, int t, const vector<EdgeIter> &path, int flow)
{
  for (int i = 0; s != t; i++) {
    if (path[i]->is_real) {
      path[i]->flow += flow;
      path[i]->partner->cap += flow;
    } else {
      path[i]->cap -= flow;
      path[i]->partner->flow -= flow;
    }
    s = path[i]->to;
  }
}

// the path is stored in a peculiar way for efficiency: path[i] is the
// i-th edge taken in the path.
int augmenting_path(const Graph &G, int s, int t, vector<EdgeIter> &path,
		    vector<bool> &visited, int step = 0)
{
  if (s == t) {
    return -1;
  }
  for (EdgeIter it = G.nbr[s].begin(); it != G.nbr[s].end(); ++it) {
    int v = it->to;
    if (it->residual() > 0 && !visited[v]) {
      path[step] = it;
      visited[v] = true;
      int flow = augmenting_path(G, v, t, path, visited, step+1);
      if (flow == -1) {
	return it->residual();
      } else if (flow > 0) {
	return min(flow, it->residual());
      }
    }
  }
  return 0;
}

// note that the graph is modified
int network_flow(Graph &G, int s, int t)
{
  vector<bool> visited(G.num_nodes);
  vector<EdgeIter> path(G.num_nodes);
  int flow = 0, f;

  do {
    fill(visited.begin(), visited.end(), false);
    if ((f = augmenting_path(G, s, t, path, visited)) > 0) {
      push_path(G, s, t, path, f);
      flow += f;
    }
  } while (f > 0);

  return flow;
}


struct Resident {
  string name;
  string party;
  int p;
  vector<int> c;
};

// graph size = 1 src + 1 sink + #ppl + #parties + #clubs
// graph max nodes estimate = 1000 people + 1000 parties + (80*1000) clubs + 2
// graph max nodes is approx = 82002
// acutal... closer to 50000 bc charaters also include spaces and name/party
// 80 characters w/ name party clubs
// so a b c d ...etc -> no two people are in the same club = 76/2 = 38 clubs
map<string, int> party;
map<string, int> clubs;
map<int, string> _clubs;
vector<Resident> people;

// input function
void input() {
  people.clear();
  party.clear();
  clubs.clear();
  _clubs.clear();
  string temp;
  while(getline(cin, temp) && temp != "") {
    istringstream ss(temp);
    Resident r;
    ss >> r.name >> r.party;
    if(party.find(r.party) == party.end()) {
      party.emplace(r.party, party.size());
    }
    r.p = party[r.party];

    string s;
    while(ss >> s) {
      if(clubs.find(s) == clubs.end()) {
        clubs.emplace(s, clubs.size());
        _clubs.emplace(clubs.size()-1, s);
      }
      r.c.push_back(clubs[s]);
    }
    people.push_back(r);
  }
}

//create graph
//src = 0, sink = 1, clubs = 2-(#clubs+1), ppl = (#clubs+2)-(#clubs+#ppl+1)
// for ex 1 club, person 0 changes to +2+#clubs = 0+2+1 = 3
// and person n (this case 2) changes to +2+#clubs+#ppl-1 or +1+#clubs+#ppl = 4
//parties = (#ppl+#clubs+2)-(#party+#ppl+#clubs+1)
void createGraph(Graph &G) {
  int numC = clubs.size();
  int numPpl = people.size();
  int numP = party.size();
  int cap = (numC-1)/2;
  //connect src to clubs
  for(int i=2; i<numC+2; i++) {
    G.add_edge(0, i, 1);
  }
  //connect parties to sink
  for(int i=numPpl+numC+2; i<numP+numPpl+numC+2; i++) {
    G.add_edge(i, 1, cap);
  }
  //connect people

  int j = 0;
  for(int i=numC+2; i<numC+numPpl+2; i++, j++) {
    //connect people to parties
    G.add_edge(i, people[j].p+numPpl+numC+2, 1);
    //connect people to clubs
    for(int &k : people[j].c) {
      G.add_edge(k+2, i, 1);
    }
  }
}

int main() {
  int t;
  cin >> t;
  cin.ignore();
  string temp;
  getline(cin, temp);
  //get input
  while(t--) {
    input();
    int n = 2 + party.size() + people.size() + clubs.size();
    int s = 0;
    int t = 1;

    Graph G(n);
    //build graph
    createGraph(G);
    //run network flow
    int flow = network_flow(G, s, t);
    if(flow < clubs.size()) {
      cout << "Impossible." << endl;
    }
    else {
      // Go through all clubs nodes 2 - (#clubs+1)
      for(int i=2; i<clubs.size()+2; i++) {
        //Go through all edges for each club
        for(Edge a : G.nbr[i]) {
          if(a.is_real && a.flow > 0) {
            // a.to will be person, which can lookup in vector
            // person is between numC+2 amd numC+numPpl+1
            int person = a.to - 2 - clubs.size();
            cout << people[person].name << " " << _clubs[i-2] << endl;
          }
        }
      }

    }
    if(t) {
      cout << endl;
    }
  }
  return 0;
}

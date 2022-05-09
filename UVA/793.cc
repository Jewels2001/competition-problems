/*
By: Julie Wojtiw-Quo
Used code from unionfind.cc in the code library. Uses union-find to connect/
merge computers and also find whether they are currently connected. Important to
decrement the computer inputs as UnionFind class uses 0-based indexing, not 1.
*/
#include <bits/stdc++.h>
using namespace std;

// UnionFind class -- based on Howard Cheng's C code for UnionFind
// Modified to use C++ by Rex Forsyth, Oct 22, 2003
//
// Constuctor -- builds a UnionFind object of size n and initializes it
// find -- return index of x in the UnionFind
// merge -- updates relationship between x and y in the UnionFind


class UnionFind
{
      struct UF { int p; int rank; };

   public:
      UnionFind(int n) {          // constructor
	 howMany = n;
	 uf = new UF[howMany];
	 for (int i = 0; i < howMany; i++) {
	    uf[i].p = i;
	    uf[i].rank = 0;
	 }
      }

      ~UnionFind() {
         delete[] uf;
      }

      int find(int x) { return find(uf,x); }        // for client use

      bool merge(int x, int y) {
	 int res1, res2;
	 res1 = find(uf, x);
	 res2 = find(uf, y);
	 if (res1 != res2) {
	    if (uf[res1].rank > uf[res2].rank) {
	       uf[res2].p = res1;
	    }
	    else {
	       uf[res1].p = res2;
	       if (uf[res1].rank == uf[res2].rank) {
		  uf[res2].rank++;
	       }
	    }
	    return true;
	 }
	 return false;
      }

   private:
      int howMany;
      UF* uf;

      int find(UF uf[], int x) {     // recursive funcion for internal use
	 if (uf[x].p != x) {
	    uf[x].p = find(uf, uf[x].p);
	 }
	 return uf[x].p;
      }
};

void solve(const int& x, int& success, int& unsuccess) {
  UnionFind uf(x);
  string temp;
  cin.ignore();

  while(getline(cin, temp)) {
    if(temp == "") {
      break;
    }
    istringstream ss(temp);
    char q;
    int a, b;
    ss >> q >> a >> b;
    --a;
    --b;
    if(q == 'c') {
      uf.merge(a, b);
    }
    else if(q == 'q') {
      if(uf.find(a) == uf.find(b)) {
        success++;
      }
      else {
        unsuccess++;
      }
    }
  }
}

int main() {
  int n;
  cin >> n;
  while(n--) {
    int success = 0;
    int unsuccess = 0;
    int x;
    cin >> x;
    solve(x, success, unsuccess);
    cout << success << ',' << unsuccess << endl;
    if(n > 0) {
      cout << endl;
    }
  }
  return 0;
}

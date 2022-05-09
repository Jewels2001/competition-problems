/*
By: Julie Wojtiw-Quo
Created a struct to hold the index, time and fine of a job. Made a custom sort
function for sorting jobs. If the time*fine of job 1 is smaller than the
time*fine of job2, job1 and job2 are in the right order. Otherwise, swap them.
If they are equal, sort them by their indicies. Applied the sort function and
outputted the indicies of the jobs.
*/

#include <bits/stdc++.h>
using namespace std;
#define debug(a) cerr << #a << " = " << (a) << endl;

struct job {
  int i;
  int t;
  int s;
};

bool f(const job& a, const job& b) {
  if(a.t * b.s < b.t * a.s) {
    return true;
  } else if(a.t * b.s > b.t * a.s) {
    return false;
  } else {
    return a.i < b.i;
  }
}

int main() {
  int cases;
  cin >> cases;
  while(cases--) {
    int n;
    cin >> n;
    vector<job> a(n);
    for(int i=0; i<n; i++) {
      a[i].i = i+1;
      cin >> a[i].t >> a[i].s;
    }
    sort(begin(a), end(a), f);
    int i=0;
    for(i=0; i<n-1; i++) {
      cout << a[i].i << " ";
    }
    cout << a[i].i;
    cout << endl << endl;
  }
  return 0;
}

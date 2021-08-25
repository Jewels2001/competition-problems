#include <bits/stdc++.h>
using namespace std;



int bitmask[9] = {11, 23, 38, 89, 186, 308, 200, 464, 416};


void recursion(int& logic) {
  int clicks = 0;
  //511 == number of possible board state combinations excluding all white(2^9-1)
  int dP[511];
  fill(dP, dP+511, -1);

  queue<int> q;
  //queue initialized to starting board
  q.push(logic);
  dP[logic] = 0;

  //when queue is empty, we will be at last possible board state (empty)
  //all board states are brute force tried in a queue
  while(!q.empty()) {
    int current = q.front();
    q.pop();

    for(int k=0; k<9; k++) {
      int next = bitmask[k] ^ current;
      if(dP[next] < 0) {
        //if we haven't visited, set to value of current combination+1
        //queue is filled with next possible combination
        dP[next] = dP[current] + 1;
        q.push(next);
      }
    }
  }
  cout << dP[0] << endl;
}


int main(){
  int p = 0;
  cin >> p;
  while(p--) {
    int clicks;
    int logic = 0;
    char c;
    //array [0,1,2,3,4,5,6,7,8] corresponds to tiles
    for(int i =0; i<3; i++){
      for(int j =0; j <3; j++){
        cin >> c;
        if(c == '*') {
          logic |= (1 << ((3*i)+j));
        //sum of (mask | (1 << j), i+1)  "mask | (1 << j)" is bitmasking j by or.
        }
        //cout << "This is i: " << i << " j: " << j << " converted: " << logic << endl;
      }
    }
    recursion(logic);
  }
  return 0;
}

/* ***Original Idea:***
int G[9][9] = {{1, 1, 0, 1, 1, 0, 0, 0, 0},
              {1, 1, 1, 0, 1, 0, 0, 0, 0},
              {0, 1, 1, 0, 0, 1, 0, 0, 0},
              {1, 0, 0, 1, 1, 0, 1, 0, 0},
              {0, 1, 0, 1, 1, 1, 0, 1, 0},
              {0, 0, 1, 0, 1, 1, 0, 0, 1},
              {0, 0, 0, 1, 0, 0, 1, 1, 0},
              {0, 0, 0, 0, 1, 0, 1, 1, 1},
              {0, 0, 0, 0, 0, 1, 0, 1, 1}};

brute force recursion:
int max_num_of_flips = INT_MAX;
int count = 0;
for(logic[i][j])
  if black(*)
    check G[i] and for each logic[i][j] if 1 then count++
if (count < max_num_of_flips)
  max_num_of_flips == count;

//still needs a way to BFS/track which one started at
*/

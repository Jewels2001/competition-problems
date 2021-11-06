#include <bits/stdc++.h>
using namespace std;

int main(){
// A, A#, B, C, C#, D, D#, E, F, F#, G, G#
// major scale = tone, tone, semitone, tone, tone, tone, semitone

//A: A, B, C#, D, E, F#, G#, A        //A#, C, D#, F, G
//A#: A#, C, D, D#, F, G, A, A#       //B, C#, E, F#, G#
//B: B, C#, D#, E, F#, G#, A#, B      //A, C, D, F, G
//C: C, D, E, F, G, A, B, C           //A#, C#, D#, F#, G#
//C#: C#, D#, F, F#, G#, A#, C, C#    //A, B, D, E, G
//D: D, E, F#, G, A, B, C#, D         //A#, C, D#, F, G#
//D#: D#, F, G, G#, A#, C, D, D#      //A, B, C#, E, F#
//E: E, F#, G#, A, B, C#, D#, E       //A#, C, D, F, G
//F: F, G, A, A#, C, D, E, F          //B, C#, D#, F#, G#
//G: G, A, B, C, D, E, F#, G          //A#, C#, D#, F, G#
//G#: G#, A#, C, C#, D#, F, G, G#     //A, B, D, E, F#
  int num;
  cin >> num;

  vector<string> scales[12];
  string notes[12] = {"A", "A#", "B", "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#"};
  int major[7] = { 2, 2, 1, 2, 2, 2, 1 };



  for(int i=0; i<12; i++){
    int index = i;
    scales[i].push_back(notes[index]);

    for(int j=0; j<7;j++) {
      index += major[j];
      index %= 12;
      scales[i].push_back(notes[index]);
    }
  }

  string song[100];
  for(int i=0;i<num;i++){
    cin >> song[i];
  }

  int found = 0;
  for(int i=0; i<12; i++){
    bool same = true;
    for(int j=0; j<num;j++){
      same &= find(begin(scales[i]), end(scales[i]), song[j]) != end(scales[i]);
    }
    if (same) {
      cout << notes[i] << ' ';
      found++;
    }
  }
  if (!found) {
    cout << "none" << endl;
  }
  cout << endl;
  return 0;
}

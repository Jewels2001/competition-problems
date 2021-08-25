#include <iostream>
#include <string>
#include <vector>

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

  vector<string> scales;
  string myStrings[12] = {'A', 'A#', 'B', 'C', 'C#', 'D', 'D#', 'E', 'F', 'F#', 'G', 'G#'}
  int major[7] = { 2, 2, 1, 2, 2, 2, 1 };


  vector<string> notes;
  for(int i=0; i<notes.size(); i++){
    int index = i;
    scales[i].push_back(notes[index]);
    bool same = false;
    for(int j=0; j<notes.size()<j++){
      if(notes.at(j) == notes.at(i)){
        notes.erase(i);
    }
  }

    for(int i=0; i<num; i++){
      if(!(notes.at(i) )
    }
  }

  for(int i=0;i<notes.size();i++){
    for(int j=0; j<)
    if((notes.at(j)== myStrings[])
  }

  cout << "none" << endl;
  return 0;
}

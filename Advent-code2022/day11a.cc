#include <bits/stdc++.h>
using namespace std;

struct Monkey {
    char opChar = ' ';
    int opNum = -1;
    int test = -1;
    int t = -1;
    int f = -1;
};

const int monkeys = 4;
const int ROUNDS = 20;
vector<queue<int>> worry(monkeys, queue<int>());
vector<Monkey> lol(monkeys);

vector<int> inspections(monkeys, 0);


int monkeyTurn(int monkeyNum, int currentMonkeyBusi) {
    int curr = currentMonkeyBusi;
    while(!worry[monkeyNum].empty()){
        int item = worry[monkeyNum].front(); worry[monkeyNum].pop();
        int n= 0;
        if(lol[monkeyNum].opNum = -1) {
          lol[monkeyNum].opNum = n;
        }
        cout << "here" << endl;
        switch(lol[monkeyNum].opChar) {
            case('*'):
                n = item * lol[monkeyNum].opNum;
                break;
            case('+'):
                n = item + lol[monkeyNum].opNum;
                break;
        }
        cout << "not" << endl;
        n /= 3;
        cout << lol[monkeyNum].test << " " << lol[monkeyNum].t << " " << lol[monkeyNum].f << endl;
        if((n % lol[monkeyNum].test) == 0) {
            worry[lol[monkeyNum].t].push(n);
        } else {
            worry[lol[monkeyNum].f].push(n);
        }
        cout << "what" << endl;

        curr++;
    }
    return curr;
}





int main() {
    string a;
    for(int i=0; i<monkeys; i++) {
        // monkey number
        getline(cin, a);
        Monkey yolo;
        // startin items
        getline(cin, a);
        string temp;
        int aa;
        stringstream ss;
        ss << a;
        ss >> temp >> temp;
        char wow;
        while(ss >> aa) {
          ss >> wow;
            worry[i].push(aa);
            cout << aa << endl;
        }
        //operation
        getline(cin, a);
        cout << "HI" << a << endl;
        char smh;
        string aaah = " ";
        ss << a;
        ss >> temp >> temp >> temp >> temp >> smh >> aaah;
        yolo.opChar = smh;
        if(isdigit(aaah[0])) {
          yolo.opNum = stoi(aaah);
        } else if(aaah == "old") {
          yolo.opNum = -1;
        }
        //yolo.opNum = aa;
        // test
        getline(cin, a);
        cout << "HI" << a << endl;
        ss << a;
        ss >> temp >> temp >> temp >> aa;
        yolo.test = aa;
        //true
        getline(cin, a);
        cout << "HI" << a << endl;
        ss << a;
        ss >> temp >> temp >> temp >> temp >> temp >> aa;
        yolo.t = aa;
        //false
        getline(cin, a);
        cout << "HI" << a << endl;
        ss << a;
        ss >> temp >> temp >> temp >> temp >> temp >> aa;
        cout << aa << endl;
        yolo.f = aa;

        lol[i] = yolo;
        getline(cin, a);
    }

    int round = 0;
    int inspected = 0;
    while(round < ROUNDS) {
        for(int i=0; i<monkeys; i++) {
            int curr = inspections[i];
            curr = monkeyTurn(i, curr);
            inspections[i] = curr;
        }
        round++;
    }

    int ans = 1;
    sort(begin(inspections), end(inspections));
    for(int i=0; i<inspections.size(); i++) {
        cout << inspections[i] << endl;
    }



}

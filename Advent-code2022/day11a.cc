#include <bits/stdc++.h>
using namespace std;

struct Monkey {
    char opChar = ' ';
    int opNum;
    int test;
    int t;
    int f;
};

const int monkeys = 9;
const int ROUNDS = 20;
vector<queue<int>> worry(9, queue<int>());
vector<Monkey> lol(9);

vector<int> inspections(9, 0);


int monkeyTurn(int monkeyNum, int currentMonkeyBusi) {
    int curr = currentMonkeyBusi;
    for(int i=0; i<worry[monkeyNum].size(); i++) {
        int item = worry[monkeyNum].front(); worry[monkeyNum].pop();
        int n= 0;
        switch(lol[monkeyNum].opChar) {
            case('*'):
                n = item * lol[monkeyNum].opNum;
                break;
            case('+'):
                n = item + lol[monkeyNum].opNum;
                break;
        }
        n /= 3;
        if((n % lol[monkeyNum].test) == 0) {
            worry[lol[monkeyNum].t].push(n);
        } else {
            worry[lol[monkeyNum].f].push(n);
        }

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
        while(ss >> aa) {
            worry[i].push(aa);
            cout << aa << endl;
        }
        //operation
        getline(cin, a);
        char smh;
        ss << a;
        ss >> temp >> temp >> temp >> temp >> smh >> aa;
        yolo.opChar = smh;
        yolo.opNum = aa;
        // test
        getline(cin, a);
        ss << a;
        ss >> temp >> temp >> temp >> aa;
        yolo.test = aa;
        //true
        getline(cin, a);
        ss << a;
        ss >> temp >> temp >> temp >> temp >> temp >> aa;
        yolo.t = aa;
        //false
        getline(cin, a);
        ss << a;
        ss >> temp >> temp >> temp >> temp >> temp >> aa;
        yolo.f = aa;

        lol[i] = yolo;
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
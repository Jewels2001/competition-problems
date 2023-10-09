#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Monkey {
    char opChar = ' ';
    ll opNum = -1;
    ll test = -1;
    ll t = -1;
    ll f = -1;
};

const ll monkeys = 8;
const ll ROUNDS = 10000;
vector<queue<ll>> worry(monkeys, queue<ll>());
vector<Monkey> lol(monkeys);

vector<ll> inspections(monkeys, 0);


ll monkeyTurn(ll monkeyNum, ll currentMonkeyBusi) {
    cout << "Monkey " << monkeyNum << "'s turn:" << endl;
    ll curr = currentMonkeyBusi;
    while(!worry[monkeyNum].empty()){
        ll item = worry[monkeyNum].front(); worry[monkeyNum].pop();
        cout << "  Monkey inspects item with worry level " << item << endl;
        bool swit = false; 
        if(lol[monkeyNum].opNum == -1) {
            swit = true;
        }
        
        switch(lol[monkeyNum].opChar) {
            case('*'):
                if(!swit) {
                    cout << "Worry level multiplied by " << lol[monkeyNum].opNum;
                    item = item * lol[monkeyNum].opNum;
                    cout << " to produce " << item << endl;
                } else {
                    cout << "Worry level multiplied by " << item;
                    item = item * item;
                    cout << " to produce " << item << endl;
                }
                break;
            case('+'):
                if(!swit) {
                    cout << "Worry level increased by " << lol[monkeyNum].opNum;
                    item = item + lol[monkeyNum].opNum;
                    cout << " to produce " << item << endl;
                } else {
                    cout << "Worry level increased by " << item;
                    item = item + item;
                    cout << " to produce " << item << endl;
                }
                break;
        }
        //sitem /= 3;
        cout << "  Bored, worry level is now " << item << endl;
        cout << lol[monkeyNum].test << " " << lol[monkeyNum].t << " " << lol[monkeyNum].f << endl;
        if((item % lol[monkeyNum].test) == 0) {
            cout << "  Current level IS divisible by " << lol[monkeyNum].test << endl;
            worry[lol[monkeyNum].t].push(item);
            cout << "  Item with worry level " << item << " thrown to monkey " << lol[monkeyNum].t << endl;
        } else {
            cout << "  Current level is NOT divisible by " << lol[monkeyNum].test << endl;
            worry[lol[monkeyNum].f].push(item);
            cout << "  Item with worry level " << item << " thrown to monkey " << lol[monkeyNum].f << endl;
        }
        cout << "what" << endl;

        curr++;
    }
    return curr;
}





int main() {
    string a;
    for(ll i=0; i<monkeys; i++) {
        // monkey number
        getline(cin, a);
        Monkey yolo;
        // startin items
        getline(cin, a);
        string temp;
        ll aa;
        stringstream ss(a);
        ss >> temp >> temp;
        cout << temp << endl;
        char wow;
        ss << ',';
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
        stringstream ss1(a);
        ss1 >> temp >> temp >> temp >> temp >> smh >> aaah;
        yolo.opChar = smh;
        cout << temp << " " << smh << " " << aaah << endl;
        if(isdigit(aaah[0])) {
          yolo.opNum = stoi(aaah);
        } else if(aaah == "old") {
          yolo.opNum = -1;
        }
        cout << yolo.opChar << " " << yolo.opNum << endl;
        //yolo.opNum = aa;
        // test
        getline(cin, a);
        cout << "HI" << a << endl;
        stringstream ss2(a);
        ss2 >> temp >> temp >> temp >> aa;
        yolo.test = aa;
        //true
        getline(cin, a);
        cout << "HI" << a << endl;
        stringstream ss3(a);
        ss3 >> temp >> temp >> temp >> temp >> temp >> aa;
        yolo.t = aa;
        //false
        getline(cin, a);
        cout << "HI" << a << endl;
        stringstream ss4(a);
        ss4 >> temp >> temp >> temp >> temp >> temp >> aa;
        cout << aa << endl;
        yolo.f = aa;

        lol[i] = yolo;
        getline(cin, a);
    }

    ll round = 0;
    ll inspected = 0;
    cout << "START: " << endl;
    for(ll i=0; i<monkeys; i++) {
            cout << "Monkey " << i << ": ";
            queue ex = worry[i];
            while(!ex.empty()) {
                cout << ex.front() << ", ";
                ex.pop();
            }
            cout << endl;
        }
    while(round < ROUNDS) {
        for(ll i=0; i<monkeys; i++) {
            ll curr = inspections[i];
            curr = monkeyTurn(i, curr);
            inspections[i] = curr;
        }
        cout << "After round " << round+1 << endl;
        for(ll i=0; i<monkeys; i++) {
            cout << "Monkey " << i << ": ";
            queue ex = worry[i];
            while(!ex.empty()) {
                cout << ex.front() << ", ";
                ex.pop();
            }
            cout << endl;
        }
        round++;
    }

    ll ans = 1;
    sort(rbegin(inspections), rend(inspections));
    for(ll i=0; i<inspections.size(); i++) {
        cout << "Monkey " << i << " inspected items " << inspections[i] << " times." << endl;
    }



}

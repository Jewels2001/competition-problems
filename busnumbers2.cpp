#include <bits/stdc++.h>
using namespace std;

vector<int> bus;


int main() {
    // Precompute all bus numbers
    vector<int> cubeNums;
    for(int i=1; i<75; i++) {
        int a = i*i*i;
        cubeNums.push_back(a);
    }
    //vector<int> busNums;
    map<int, int> busNums;
    for(int i=0; i<cubeNums.size(); i++) {
        for(int j=i+1; j<cubeNums.size(); j++) {
            int num = cubeNums[i]+cubeNums[j];
            //busNums.insert(pair<int, int>(num, 1);
            busNums[num]++;
            // if(busNums.insert(pair<int, int>(num, 1)).second==false) {
            //     busNums[num]++;
            // }
        }
    }
    for(auto [a, b] : busNums) {
        if(b >= 2) {
            bus.push_back(a);
        }
    }
    sort(begin(bus), end(bus));
    
    int x;
    cin >> x;
    int cur = -1;
    for(int i=0; i<bus.size(); i++) {
        if(bus[i] > cur && bus[i] <= x) {
            cur = bus[i];
        } else if(bus[i] > x) {
            break;
        }
    }

    if(cur == -1) {
        cout << "none" << endl;
    } else {
        cout << cur << endl;
    }

}
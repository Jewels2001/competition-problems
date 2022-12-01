#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const double PI = acos(-1.0);
#define INF 1000000000


int main() {
    string line;
    vector<int> amounts;
    int current = 0;
    while(getline(cin, line)) {
        if(line == "") {
            cout << "newline" << endl;
            amounts.push_back(current);
            current = 0;
        }
        else {
            int temp = stoi(line);
            //cout << typeof(temp) << endl;
            //cout << temp << endl;
            current += temp;
            cout << current << endl;
        }
    }
    for(int i=0; i<amounts.size(); i++) {
        cout << amounts[i] << endl;
    }

    cout << "end" << endl;
    sort(rbegin(amounts), rend(amounts));
    // int max = 0;
    // for(auto i : amounts) {
    //     if(i >= max) {
    //         max = i;
    //     }
    // }
    // auto it = max_element(begin(amounts), end(amounts));
    // cout << amounts[it]
    //std::cout << *std::max_element(begin(amounts), end(amounts))  << endl;
    cout << amounts[0] << " " << amounts[1] << " " << amounts[2] << endl;
    cout << amounts[0] + amounts[1] + amounts[2] << endl;
  return 0;
}
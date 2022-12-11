#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    vector<ll> sizes;
    map<string, int> woo;
    woo["/"] = 0;
    sizes.push_back(0);
    string a;
    string current = ".";
    int i = 1;
    int curr = 0;
    while(getline(cin, a)) {
        stringstream s;
        s << a;
        string temp;
        s >> temp;
        if(temp == dir) {
            s >> temp;
            woo[temp] = i;
            i++;
            sizes.push_back(0);

        } else if(isdigit(temp[0])) {
            sizes[curr] += ll(temp);
        } else if(temp == "$") {
            s >> temp;
            if(temp == "cd") {
                s >> temp;
                if(temp == "..") {
                    
                }
                current == temp;
                curr = woo[temp];
            }
        }
    }
}
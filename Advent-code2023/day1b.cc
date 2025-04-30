#include <bits/stdc++.h>
using namespace std;


int main() {

    vector<string> nums{"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    //enum Nums1 {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    string line;
    int sum = 0;
    while(getline(cin, line)) {
        bool seen = false;
        string a = "0";
        int aPos = -1;
        string b = "-1";
        int bPos = -1;
        for(int i=0; i<line.length(); i++) {
            if(isdigit(line[i])) {
                if(!seen) {
                    a = line[i];
                    aPos = i;
                    seen = true;
                } else {
                    b = line[i];
                    bPos = i;
                }
            }
        }
        if(b == "-1") {
            b = a;
            bPos = aPos;
        }

        for(int i=1; i<nums.size(); i++) {
            if(line.find(nums[i]) != string::npos) {
                int spot = line.find(nums[i]);
                //cerr << "A:" << spot << endl;
                if(spot < aPos || aPos == -1) {
                    aPos = spot;
                    a = to_string(i);
                }
            }
            if(line.rfind(nums[i]) != string::npos) {
                int spot = line.rfind(nums[i]);
                //cerr << "B: "<< spot << endl;
                if(spot > bPos || bPos == -1) {
                    bPos = spot;
                    b = to_string(i);
                }
            }
        }



        string c = a+b;
        //cerr << c << endl;

        sum += stoi(c);
    }
    cout << sum << endl;
}
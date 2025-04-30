#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int convert(char a, string source) {
    for(int i=0; i<source.length(); i++) {
        if(source[i] == a) {
            return i;
        }
    }
    return 0;
}


int main() {
    int t;
    cin >> t;
    int caseNo = 1;
    while(t--) {
        string num, sourceLang, targetLang;
        cin >> num >> sourceLang >> targetLang;

        int sL = sourceLang.length();
        int tL = targetLang.length();

        reverse(begin(num), end(num));

        ll rep = 0;
        for(int j=0; j<num.length(); j++) {
            rep += convert(num[j], sourceLang) * (pow(sL, j));
        }

        string ans = "";
        while(rep > 0) {
            ans += targetLang[rep % tL];
            rep /= tL;
        }

        reverse(begin(ans), end(ans));

        cout << "Case #" << caseNo << ": ";
        cout << ans;
        cout << endl;
        caseNo++;
    }
}
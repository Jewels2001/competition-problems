#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<int> vi;

#define INF 1000000000
#define fst first
#define snd second
#define debug(a) cerr << #a << " = " << (a) << endl;
#define sz(x) (int)(x).size()
#define all(X) begin(X), end(X)
#define rall(X) rbegin(X), rend(X)

double time() { return double(clock()) / CLOCKS_PER_SEC; }

template<typename T, typename U> ostream& operator<<(ostream& o, const pair<T, U>& x) { o << "(" << x.fst << ", " << x.snd << ")"; return o; }
template<typename T> ostream& operator<<(ostream& o, const vector<T>& x) { o << "["; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "]"; return o; }
template<typename T> ostream& operator<<(ostream& o, const set<T>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T> ostream& operator<<(ostream& o, const multiset<T>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T> ostream& operator<<(ostream& o, const unordered_set<T>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T> ostream& operator<<(ostream& o, const unordered_multiset<T>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T, typename U> ostream& operator<<(ostream& o, const map<T, U>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T, typename U> ostream& operator<<(ostream& o, const multimap<T, U>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T, typename U> ostream& operator<<(ostream& o, const unordered_map<T, U>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T, typename U> ostream& operator<<(ostream& o, const unordered_multimap<T, U>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }


int main() {
    int N,W; cin>>N>>W;
    vector<string> G(N), Gres(N);
    string green = "-----";
    set<char> yellowSet;
    set<char> greenSet;
    set<char> greySet;
    for(int i=0; i<N; ++i) {
        cin>>G[i]>>Gres[i];
        for(int j=0; j<5; ++j) {
            if(Gres[i][j] == 'G') {
                green[j] = G[i][j];
                greenSet.insert(G[i][j]);
            }
        }
    }

    for(int i=0; i<N; ++i) {
        set<char> missing;
        for(int j=0; j<5; ++j) {
            if(green[j] != '-' && G[i][j] != green[j])
                missing.insert(green[j]);
        }

        for(int j=0; j<5; ++j) {
            if(Gres[i][j] == 'Y') {
                if(missing.find(G[i][j]) == missing.end()) {
                    yellowSet.insert(G[i][j]);
                }
            }
        }
    }

    for(int i=0; i<N; ++i) {
        for(int j=0; j<5; ++j) {
            if(Gres[i][j] == '-')
                greySet.insert(G[i][j]);
        }
    }

    debug(green);
    debug(greenSet);
    debug(yellowSet);

    for(int i=0; i<W; ++i) {
        string S; cin>>S;
        bool good = true;
        for(int j=0; j<5 && good; ++j) {
            if(green[j] != '-') {
                if(S[j] != green[j])
                    good = false;
            }
            else {
                if(yellowSet.find(S[j]) == yellowSet.end() && greySet.find(S[j]) != greySet.end())
                    good = false;
            }
        }
        if(good)
            cout<<S<<endl;
    }

}

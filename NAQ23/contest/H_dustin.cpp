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

const double PI = acos(-1);
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

ll N,S,K;
vector<ll> X;

bool f(ll D) {
    cout<<"D = "<<D<<endl;
    vector<pair<double,double>> dis(sz(X));
    ll minD = INT_MAX;
    for(int i=0; i<sz(X); ++i) {
        if(!i)
            dis[i].fst = INT_MAX;
        else
            dis[i].fst = X[i]-X[i-1];

        if(i==sz(X)-1)
            dis[i].snd = INT_MAX;
        else
            dis[i].snd = X[i+1]-X[i];

        minD = min(minD,(ll)min(dis[i].fst,dis[i].snd));
    }

    if(minD < S) return false;

    vi idx(sz(dis));
    for(int i=0; i<sz(dis); ++i)
        idx[i] = i;
    sort(all(idx), [dis](const int &i, const int &j) {
        auto a = dis[i];
        auto b = dis[j];
        if(max(a.fst,a.snd) == max(b.fst,b.snd)) {
            return min(a.fst,a.snd) > min(b.fst,b.snd);
        } else 
            return max(a.fst,a.snd) > max(b.fst,b.snd);
    });

    ll total = 0;
    for(int i:idx) {
        double s = min(dis[i].fst,dis[i].snd);
        total += min(K, (ll)((2*s)-1));  
    }
    debug(total);

    return total == D;
}

int main() {
    cin>>N>>S>>K;

    X.resize(N);
    for(ll &i:X)
        cin>>i;

    sort(all(X));

    ll hi=N*K;
    ll lo=0;
    while(hi>lo+1) {
        ll mid = (lo+hi)/2;
        if(f(mid))
            lo = mid;
        else
            hi = mid;
    }

    cout<<lo<<endl;
}

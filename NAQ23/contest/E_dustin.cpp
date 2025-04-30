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

int N,M;
vector<string> B;

int doors = 0;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};

bool bounds(int i, int j) {
    return i>=0 && i<N && j>=0 && j<M;
}

int main() {
    cin>>N>>M;cin.ignore();

    B.resize(N);
    for(string &s:B)
        getline(cin,s);

    vector<vi> V(N,vi(M,0));
    for(int i=0; i<N; ++i) {
        for(int j=0; j<M; j+= (i==0||i==N-1)?1:M-1) {
            if(B[i][j] != 'X') {
                doors++;
                int dots=0;
                 
    
//                cout<<"BFS "<<B[i][j]<<endl;

                queue<pii> Q;
                Q.push(make_pair(i,j));
                V[i][j] = 1;
                while(!Q.empty()) {
                    pii cur = Q.front();
                    Q.pop();

                    if(B[cur.fst][cur.snd] == '.') {
                        dots++;
                        B[cur.fst][cur.snd] = ' ';
                    }

//                    if(B[cur.fst][cur.snd] >= 'A' && B[cur.fst][cur.snd] <= 'Z' && B[cur.fst][cur.snd] != 'X')
//                        B[cur.fst][cur.snd] = 'X';

                    for(int k=0; k<4; ++k) {
                        pii next = cur;
                        next.fst+=dy[k];
                        next.snd+=dx[k];
                        if(bounds(next.fst,next.snd) && (B[next.fst][next.snd] < 'A' || B[next.fst][next.snd] > 'Z') && !V[next.fst][next.snd]) {
                            V[next.fst][next.snd] =1;
                            Q.push(next);
                        }
                    }
                }

                if(!dots)
                    doors--;
            }
        }
    }

    int dots=0;
    for(int i=0; i<N; ++i)
        for(int j=0; j<M; ++j)
            dots += B[i][j] == '.';
    cout<<doors<<" "<<dots<<endl;

//    cout<<endl;
//    for(int i=0; i<N; ++i) {
//        for(int j=0; j<M; ++j)
//            cout<<B[i][j];
//        cout<<endl;
//    }
}

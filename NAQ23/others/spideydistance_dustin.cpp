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

// Change this to whatever integer data type will prevent overflow
//   - BigInteger works with this class
typedef long long int dataType;

class Fraction{
public:
  Fraction(dataType num=0,dataType denom=1);
	
  double toDouble() const;
	
  void reduce();
	
  // Changes the fraction itself.
  void selfReciprocal();
	
  // Returns a new fraction, leaving the original.
  Fraction reciprocal() const;
	
  Fraction& operator+=(const Fraction& x);
  Fraction& operator-=(const Fraction& x);
  Fraction& operator*=(const Fraction& x);
  Fraction& operator/=(const Fraction& x);
	
  bool operator<(const Fraction& x) const;
  bool operator==(const Fraction& x) const;
	
  dataType num,denom;
};

Fraction operator+(const Fraction& x,const Fraction& y);
Fraction operator-(const Fraction& x,const Fraction& y);
Fraction operator*(const Fraction& x,const Fraction& y);
Fraction operator/(const Fraction& x,const Fraction& y);

istream& operator>>(istream& is,Fraction& x);
ostream& operator<<(ostream& os,const Fraction& x);

Fraction::Fraction(dataType n,dataType d){
  if(d < 0){
    num = -n;
    denom = -d;
  } else {
    num = n;
    denom = d;
  }
  reduce();
}

double Fraction::toDouble() const{
  return 1.0*num/denom;
}

// Howard's GCD function with no checks
dataType gcd(dataType a, dataType b)
{
  dataType r;
  while (b) {
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}

void Fraction::reduce(){
  dataType g = gcd(abs(num),denom);
  num /= g;
  denom /= g;
}

void Fraction::selfReciprocal(){
  swap(num,denom);
  if (denom < 0) {
    num = -num;
    denom = -denom;
  }
}

Fraction Fraction::reciprocal() const{
  return Fraction(denom,num);
}

// Overflow potential in the denominator.
// I've tried to factor out as much as possible before,
//   But be careful.
//
//   (w)/(a*g) + (z)/(b*g)
// = (w*b)/(a*g*b) + (a*z)/(a*g*b)
// = (w*b + a*z)/(a*g*b)
Fraction& Fraction::operator+=(const Fraction& x){
  dataType g = gcd(denom,x.denom);
	
  dataType a = denom / g;
  dataType b = x.denom / g;
	
  num = num * b + x.num * a;
  denom *= b;
	
  reduce();
	
  return (*this);
}

Fraction& Fraction::operator-=(const Fraction& x){
  dataType g = gcd(denom,x.denom);
  dataType a = denom / g;
  dataType b = x.denom / g;
	
  num = num * b - x.num * a;
  denom *= b;
	
  reduce();
  return (*this);
}

Fraction& Fraction::operator*=(const Fraction& x){
  num *= x.num;
  denom *= x.denom;
  reduce();
  return (*this);
}

Fraction& Fraction::operator/=(const Fraction& x){
  num *= x.denom;
  denom *= x.num;
	
  if(denom < 0){
    num = -num;
    denom = -denom;
  }
  reduce();
  return (*this);
}

// Careful with overflow. If it is an issue, you can compare the
// double values, but you SHOULD check for equality BEFORE converting
bool Fraction::operator<(const Fraction& x) const{
  return (num*x.denom) < (x.num*denom);
}

bool Fraction::operator==(const Fraction& x) const{
  return (num == x.num) && (denom == x.denom);
}

Fraction operator+(const Fraction& x,const Fraction& y){
  Fraction a(x);
  a += y;
  return a;
}

Fraction operator-(const Fraction& x,const Fraction& y){
  Fraction a(x);
  a -= y;
  return a;
}

Fraction operator*(const Fraction& x,const Fraction& y){
  Fraction a(x);
  a *= y;
  return a;
}

Fraction operator/(const Fraction& x,const Fraction& y){
  Fraction a(x);
  a /= y;
  return a;
}

// Note that you can read in Fractions of two forms:
// a/b (With any number of space between a,/,b) - The input "points" to
//      the NEXT character after the denom (White space or not)
// c   (Just an integer - The input "points" to the next NON-WHITE SPACE
//      character. Careful when mixing this with getline.)
istream& operator>>(istream& is,Fraction& x){
  is >> x.num;
	
  char ch;
  is >> ch;
  if(ch != '/'){
    is.putback(ch);
    x.denom = 1;
  } else {
    is >> x.denom;
    if(x.denom < 0){
      x.num = -x.num;
      x.denom = -x.denom;
    }
    x.reduce();
  }
	
  return is;
}

// Will output 5 for 5/1 and 0 for 0/1. If you want always
//    fractions, get rid of the if statement
ostream& operator<<(ostream& os,const Fraction& x){
  os << x.num;
  if(x.num != 0 && x.denom != 1)
    os << '/' << x.denom;
  return os;
}

int main() {
    ll T,S; cin>>T>>S;

    ll TD = 0;
    ll SD = 0;
    for(int y=-max(T,S); y<=max(T,S); ++y) {
        // debug(y);
        ll tInt=0, sInt=0;
        if(y<=T&&y>=-T)
            tInt = (T-abs(y))+1;
        if(y<=S&&y>=-S) {
            if(S >= 1.5*abs(y))
                sInt = floor(abs(y) + (S - 1.5*abs(y)))+1;
            else
                sInt = 2 * (S-abs(y))+1;
        }

        // debug(tInt);
        // debug(sInt);

        if(tInt > sInt)
            TD+=sInt;
        else
            TD+=tInt;
        SD+=sInt;
        // debug(TD);
        // debug(SD);
    }
    SD *= 2;
    TD *= 2;
    SD -= (S*2)+1;
    TD -= (min(S,T)*2)+1;
    // debug(TD);
    // debug(SD);

    Fraction ans(TD,SD);
    debug(ans);
    if(ans.num >= ans.denom) {
        cout<<1<<endl;
        return 0;
    }
    
    ans.reduce();
    cout<<ans<<endl;
}

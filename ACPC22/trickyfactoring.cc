#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX_NUM = 1000000;
vector<ll> primes;


// idk if this stuff is needed


void genSmallPrimes() {
	bool isPrime[MAX_NUM];
	for(int  i=3; i<MAX_NUM; i+=2)
		isPrime[i] = true;
	primes.clear();
	primes.push_back(2);

	int i;
	for(i=3;i*i<MAX_NUM; i+=2)
		if(isPrime[i]) {
			primes.push_back(i);
			for(int j=i*i; j<MAX_NUM; j+=(2*i))
				isPrime[j] = false;
		}
	for(;i<MAX_NUM;i+=2)
		if(isPrime[i])
			primes.push_back(i);
}

void printEntry(bool &printed, ll prime, int ex, vector<ll> &v) {
	if(!printed)
		printed=true;
	for(int i=0; i<ex; ++i)
		v.push_back(prime);
}

vector<ll> factor(ll x) {
	vector<ll> v;
	bool printed = false;
	for(int i=0; i<primes.size(); i++)
		if(x % primes[i] == 0) {
			int ex = 0;
			do {
				x /= primes[i];
				ex++;
			} while(x% primes[i] == 0);
			printEntry(printed, primes[i], ex, v);
		}
	if(x == 1) {
		cout << endl;
		return v;
	}
	// idk if this stuff is needed
//	if(lgPrimes.find(x) != lgPrimes.end()) 

}


//vector<ll> myFactor(ll x) {
//	vector<ll> nums;
//	for(int i=0; i<numPrimes; i++)
//		if(x % primes[i] == 0) {
//			do {
//				x /= primes[i];
//				num.push_back(primes[i];
//			} while(x% primes[i] == 0;
//		}
//	if(x == 1)
//		return;
//	//if x is prime
//	if(
//}


int main() {
	genSmallPrimes();
	ll a, c;
	cin >> a >> c;
	
	vector<ll> a_factors = factor(a);
	vector<ll> c_factors = factor(c);

	ll mult = 3;
	if(a == 1 || c == 1) {
		mult = 2;
	}
	
    set<ll> a2;

	ll a_size = a_factors.size();
	ll c_size = c_factors.size();


	cout<<"A"<<endl;
	cout << a_size << endl;

/*	for(ll i:a_factors)
		cout<<i<<" ";
	cout<<endl;
*/
	cout<<"C"<<endl;
	cout << c_size << endl;
	/*
	for(ll i:c_factors)
		cout<<i<<" ";
	cout<<endl;
	*/
}

#include <bits/stdc++.h>

using namespace std;

int add(const int& a, const int& b) {	
	return a + b;
}

int sub(const int& a, const int& b) {
	return a - b;
}


int mult(const int& a, const int& b) {
	return a * b;
}


int divide(const int& a, const int& b) {
	int a4 = 0;
	if(a % b == 0) {
		a4 = a / b;
	}
	return a4;
}


int main() {
	int a, b, c;
	cin >> a >> b >> c;
	int a1 = add(a, b);
	int a2 = sub(a, b);
	int a3 = mult(a, b);
	int a4 = divide(a, b);

	vector<int> abc = { a1, a2, a3, a4 };

	int ans = INT_MAX;

	for(int i=0; i<4; i++) {
		if(i == 3) {
			if(abc[i] == 0) {
				continue;
			}
		}
		int b1 = add(abc[i], c);
		int b2 = sub(abc[i], c);
		int b3 = mult(abc[i], c);
		int b4 = divide(abc[i], c);

		if(b1 >= 0) {
			ans = min(ans, b1);
		}
		if(b2 >= 0) {
			ans = min(ans, b2);
		}
		if(b3 >= 0) {
			ans = min(ans, b3);
		}
		if(b4 > 0) {
			ans = min(ans, b4);
		}
	}
	cout << ans << endl;
}

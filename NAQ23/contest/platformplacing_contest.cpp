#include <bits/stdc++.h>

using namespace std;

int main() {

	int n, s, k;
	cin >> n >> s >> k;

	vector<int> points(n);
	for(int i=0; i<n; i++) {
		cin >> points[i];
	}
	sort(begin(points), end(points));
	int ans = 0;
	bool bad = false;

	int last = INT_MIN;
	int current = INT_MAX;
	for(int i=0; i<n; i++) {
		current = points[i];
		double dist1 = abs(current - last);
		double dist2 = INT_MAX;
		if(i+1 < n) {
			dist2 = abs(points[i+1] - current);
		}
		cout << dist1 << " " << dist2 << endl;
		// check case
		if(dist1 < s || dist2 < s) {
			bad = true;
			break;
		}
		// do spacing up to max dist
		//
		int limHalf = min(dist1, dist2);
		int len = min(limHalf*2, k);

		ans += len;
		last = current;
	}

	if(bad) {
		cout << -1 << endl;
	} else {
		cout << ans << endl;
	}
}

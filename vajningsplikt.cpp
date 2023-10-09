#include <bits/stdc++.h>
using namespace std;

int main() {
	string a, b, c;
	cin >> a >> b >> c;
	// straight
	// North, South, West
	// South, North, East
	// West, East, South
	// East, West, North

	// turn left
	// North, East, (South or West)
	// West, North, (East or South)
	// South, West, (North or East)
	// East, South, (West or North)

	if((a == "North" && b == "South" && c == "West") || (a == "South" && b == "North" && c == "East") || (a == "West" && b == "East" && c == "South") || (a == "East" && b == "West" && c == "North"))
		cout << "Yes" << endl;
	else if((a == "North" && b == "East" && (c == "South" || c == "West")) || (a == "West" && b == "North" && (c == "East" || c == "South")) || (a == "South" && b == "West" && (c == "North" || c == "East")) || (a == "East" && b == "South" && (c == "West" || c == "North")))
		cout << "Yes" << endl;
	else {
		cout << "No" << endl;
	}


return 0;
}

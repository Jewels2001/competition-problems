#include <iostream>
#include <utility>
#include <cmath>
#include <algorithm>
using namespace std;

void print(pair <int, int>* arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i].first << " " << arr[i].second << endl;
    }

}

int main() {
    int n;

    cin >> n;

    int x, y;

    pair<int, int> arr[n];

    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        arr[i].first = x;
        arr[i].second = y;
    }

    int distance  = 0;

    sort(arr, arr + n);

    for (int i = 0; i < n-1; i++) {
        for (int j = i +1; j < n; j++) {
            distance += abs(arr[i].first - arr[j].first);
            distance += abs(arr[i].second - arr[j].second);

        }
    }

    int k = 1;
    for (int i = 0; i < n; i++) {
        distance += abs(arr[i].first - arr[k];


    }


    cout << distance << endl;

    print (arr, n);

    return 0;
}

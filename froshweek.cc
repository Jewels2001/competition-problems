#include <bits/stdc++.h>
using namespace std;

// void swap(int *x, int *y){
//   int temp = *x;
//   *x = *y;
//   *y = temp;
// }
typedef long long ll;

ll merge(vector<int>& arr, vector<int>& arrTemp, int left, int mid, int right) {
  ll ans = 0;
  int i= left;
  int j=mid;
  int k=left;

  // int arrOne = mid - left +1;
  // int arrTwo = right - mid;
  //
  // int *leftArray = new int[arrOne],
  //      *rightArray = new int[arrTwo];
  //
  // for(int i =0; i< arrOne; i++)
  //   leftArray[i] = arr[left + i];
  // for(int j=0; j<arrTwo; j++)
  //   rightArray[j] = arr[mid + 1 + j];
  //
  // int indexArrOne = 0,
  //     indexArrTwo = 0;
  // int indexMergedArr = left;


  while((i <= mid-1) && (j <= right)){
    if(arr[i] <= arr[j])
      arrTemp[k++] = arr[i++];
    else{
      arrTemp[k++] = arr[j++];
      ans = ans+(mid-i);
    }
  }
  while(i <=mid-1)
    arrTemp[k++] = arr[i++];
  while(j<=right)
    arrTemp[k++] = arr[j++];
  for(i=left; i<= right; i++)
    arr[i] = arrTemp[i];
  return ans;


  // while (indexArrOne < arrOne && indexArrTwo < arrTwo) {
  //   if(leftArray[indexArrOne] <= rightArray[indexArrTwo]) {
  //     arr[indexMergedArr] = leftArray[indexArrOne];
  //     indexArrOne++;
  //   }
  //   else {
  //     arr[indexMergedArr] = rightArray[indexArrTwo];
  //     ans += (arrOne -indexArrOne);
  //     indexArrTwo++;
  //   }
  //   indexMergedArr++;
  // }
  //
  // while(indexArrOne < arrOne) {
  //   arr[indexMergedArr] = leftArray[indexArrOne];
  //   indexArrOne++;
  //   indexMergedArr++;
  // }
  // while(indexArrTwo < arrTwo) {
  //   arr[indexMergedArr] = rightArray[indexArrTwo];
  //   indexArrTwo++;
  //   indexMergedArr++;
  // }
  return ans;
}

ll mergeSort(vector<int>& arr, vector<int>& tempArr, int left, int right) {
  ll ans = 0;
  int mid = 0;

  if(right > left) {
    //int mid = begin + (end - begin) / 2;
    mid = (right + left)/2;
    ans = mergeSort(arr, tempArr, left, mid);
    ans += mergeSort(arr, tempArr, mid +1, right);
    ans += merge(arr, tempArr, left, mid+1, right);
  }
  return ans;
}



int main() {
  int n;
  cin >> n;
  vector<int> arr;
  vector<int> tempArr(n,0);
  for(int i=0;i<n;i++){
    int temp;
    cin >> temp;
    arr.push_back(temp);
  }

  ll ans = mergeSort(arr, tempArr, 0, n-1);
  cout << ans;
  return 0;
}

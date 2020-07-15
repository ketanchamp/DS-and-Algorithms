// Time Complexity- O( N log (N) )  N for extra traversing + log (N) for searching
#include<bits/stdc++.h>
using namespace std;
int longestIncreasingSubsequence(int size, vector<int> arr) {
	vector<int> tail(size, 0); // Final array containing the elements of Longest increasing sequence
	int length = 1;
	tail[0] = arr[0];
	for(int i = 1; i < size; i++){
		int index = lower_bound(tail.begin(), tail.begin() + length, arr[i]) - tail.begin();  // Search if the arr[i] is lesser than max element in tail
		if(index == length) tail[length++] = arr[i];
		else tail[index] = arr[i];
	}
	for(int i = 0; i < length; i++) cout << tail[i] << " ";
	cout << endl;
    return length;
}
int main()
{
	int size;
	cin >> size;
	vector<int> arr(size);
	for(int i = 0; i < size; i++){
		cin >> arr[i];
	}
	cout << "LIS Length : " << longestIncreasingSubsequence(size, arr) << endl;
    return 0;
}
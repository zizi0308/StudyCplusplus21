#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(int a, int b) { return a > b; }		// 받은 return값에 대해 내림차순 정렬
int main() {
	vector<int> arr;
	arr.push_back(7);
	arr.push_back(3);
	arr.push_back(5);
	arr.push_back(2);
	arr.push_back(6);

	// sort(arr.begin(), arr.end());
	sort(arr.begin(), arr.end(), compare);
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << endl;
	}
}
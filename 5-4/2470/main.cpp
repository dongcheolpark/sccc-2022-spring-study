#include <iostream>
#include <climits>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;	
	cin>>n;
	vector<int> v;
	v.resize(n);
	for(int i = 0;i<n;i++) {
		cin>>v[i];
	}
	sort(v.begin(),v.end());
	int a,b,sum = INT_MAX;
	int left = 0,right = n-1;
	while(left<right) {
		int tmp = v[right] + v[left];
		if(abs(tmp) < sum) {
			a = v[left];
			b = v[right];
			sum = abs(tmp);
			if(tmp == 0) break;
		}
		if(tmp < 0) {
			left++;
		}
		else right--;
	}
	cout<<a<<' '<<b;
}
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef unsigned long long ull;

vector<ull> v;
int k,n;
int check(ull x) {
	int sum = 0;
	for(auto item : v) {
		sum += item/x;	
	}
	return sum;
}

int main() {
	cin.tie(NULL); 
	ios::sync_with_stdio(false);

	cin>>k>>n;
	v.resize(n);
	int max = 0;
	for(int i = 0;i<k;i++) {
		cin>>v[i];
		max = max > v[i]?max:v[i];
	}
	ull left = 1,right = max+1;
	int res = 0;
	while(left <= right) {
		ull mid = (left+right)/2;
		if(check(mid)>=n) {
			left = mid+1;
			res = mid > res?mid:res;
		}
		if(check(mid)<n) {
			right = mid-1;
		}
	}
	cout<<res;
}
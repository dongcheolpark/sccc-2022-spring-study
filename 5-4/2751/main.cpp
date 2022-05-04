#include <iostream>
#include <algorithm>
#include <vector>

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
	for(int i = 0;i<n;i++) {
		cout<<v[i]<<'\n';
	}
}
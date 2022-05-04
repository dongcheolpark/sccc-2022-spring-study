#include <iostream>
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
	int m; 
	cin>>m;
	sort(v.begin(),v.end());
	for(int i = 0;i<m;i++) {
		int tmp;
		cin>>tmp;
		auto x = binary_search(v.begin(),v.end(),tmp);
		if(x) cout<<1<<'\n';
		else cout<<0<<'\n';
	}
}
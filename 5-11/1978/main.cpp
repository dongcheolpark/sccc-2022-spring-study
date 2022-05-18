#include <iostream>
#include <vector>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	vector<int> v(n);
	vector<vector<int> > field(n,vector<int>(n,0));
	for(int i = 0;i<n;i++) {
		cin>>v[i];
	}
	for(int i = 2;i<=1000;i++) {
		for(int j = i;i<=1000;j++) {
			
		}
	}

	return 0;
}
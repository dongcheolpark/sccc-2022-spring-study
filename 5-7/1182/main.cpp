#include <iostream>
#include <vector>

using namespace std;

vector<int> v;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n,m,res = 0;
	cin>>n>>m;
	int size = 2<<(n-1);
	v.resize(n);
	for(int i = 0;i<n;i++) {
		cin>>v[i];
	}
	for(int i = 1;i<size;i++) {
		int sum = 0;
		for(int j = i,k = 0;j;j/=2,k++) {
			if(j%2) {
				sum += v[k];
			} 
		}
		if(sum == m) {
			res++;
		}
	}
	cout<<res;
	return 0;
}
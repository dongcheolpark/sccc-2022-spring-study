#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	long long n,p;
	cin>>n>>p;
	long long ans = 1;
	for(int i = 2;i<=n;i++) {
		ans = (ans*i)%p;
	}
	cout<<ans;
	return 0;
}

#include <iostream>

using namespace std;

int n,p,a;

long long func(int x) {
	if(x <= 1) return a;
	long long c = func(x/2);
	c = (c*c)%p;
	if(x % 2) {
		c = (c*a)%p;
	}
	return c;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin>>a>>n>>p;
	a %= p;
	cout<<func(n);
	return 0;
}
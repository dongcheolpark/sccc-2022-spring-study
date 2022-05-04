#include <iostream>
#include <cmath>

using namespace std;

typedef unsigned long long ull;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	ull n;
	cin>>n;

	ull x = sqrt(n);
	if (x * x >= n) cout<<x;
	else cout<<x+1;
}
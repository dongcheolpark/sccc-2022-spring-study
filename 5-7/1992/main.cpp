#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector<int>> v;

int check(int x,int y,int n) {
	int tmp = v[x][y];
	for(int i = x;i<x+n;i++) {
		for(int j = y;j<y+n;j++) {
			if(tmp != v[i][j]) return -1;
		}
	}
	return tmp;
}

void func(int x,int y,int n) {
	if(n == 1) {
		printf("%d",v[x][y]);
		return;
	}
	int a = check(x,y,n);
	if(a != -1) {
		printf("%d",a);
		return;
	}
	printf("(");
	for(int i = x;i<x+n;i+=n/2) {
		for(int j = y;j<y+n;j+=n/2) {
			func(i,j,n/2);
		}
	}
	printf(")");
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin>>n;
	v.resize(n);
	for(int i = 0;i<n;i++) {
		v[i].resize(n);
	}
	for (int i = 0; i < n; i++)
	{
		string tmp;
		cin>>tmp;
		for (int j = 0; j < n; j++)
		{
			v[i][j] = tmp[j] - '0';
		}
	}
	func(0,0,n);
	return 0;
}
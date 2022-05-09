#include <iostream>
#include <vector>

using namespace std;

int n,x,y;
vector<int> v,chk;

int func(int num) {
	if(num == 2*n) {
		return 1;
	}
	int cnt = 0;
	if(!v[num]) {
		for (int i = 1; i <= n; i++)
		{
			int next = num+i+1;
			if(chk[i]|| i == y-x-1) continue;
			if(next<=2*n && !v[next]) {
				chk[i] = 1;
				v[next] = v[num] = i;
				cnt += func(num+1);
				v[next] = v[num] = 0;
				chk[i] = 0;
			}
		}
	}
	else cnt += func(num+1);
	return cnt;
}


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin>>n>>x>>y;
	v.resize(n*2+1);
	chk.resize(n*2+1);
	v[x] = v[y] = y-x-1;
	cout<<func(1);
	return 0;
}
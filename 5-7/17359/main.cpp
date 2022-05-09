#include <iostream>
#include <vector>
#include <string>
#include <utility>

using namespace std;

int n;
vector<pair<int,int>> v;
vector<pair<int,int>> res;
int ans = 1000;

bool visit[20];

void func(int cnt) {
	if(cnt == 0) {
		int sum = 0;
		for(int i = 1;i<n;i++) {
			if(res[i-1].second != res[i].first) {
				sum++;
			}
		}
		if(sum < ans) {
			ans = sum;
		}
	}
	for(int i = 0;i<n;i++) {
		if(visit[i]) continue;
		visit[i] = true;
		res[n-cnt] = v[i];
		func(cnt-1);
		visit[i] = false;
	}	
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin>>n;
	int sum = 0;
	for(int i = 0;i<n;i++) {
		string tmp;
		cin>>tmp;
		int size = tmp.size();
		for(int i = 1;i<size;i++) {
			if(tmp[i]!=tmp[i-1]) sum++;
		}
		v.push_back(make_pair(tmp[0]-'0',tmp[size-1]-'0'));
	}
	res.resize(n);
	func(n);
	cout<<ans+sum;
	return 0;
}
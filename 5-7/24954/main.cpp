#include <iostream>
#include <climits>
#include <vector>

using namespace std;

int n,res = INT_MAX,sum = 0;

vector<int> price,chk;
vector<vector<pair<int,int>>> reduce;

void func(int cnt) {
	if(cnt == n) {
		if(sum < res) res = sum;
		return;
	}

	for(int i = 0;i<n;i++) {
		if(chk[i]) continue;
		sum += price[i];
		chk[i] = 1;
		int size = reduce[i].size();
		vector<pair<int,int>> origin;
		for(int j = 0;j<size;j++) {
			int a = reduce[i][j].first,b = reduce[i][j].second;
			origin.push_back(make_pair(a,price[a]));
			price[a] -= b;
			price[a] = price[a] > 0 ? price[a] : 1;
		}
		func(cnt+1);
		for(auto item : origin) {
			price[item.first] = item.second;
		}
		chk[i] = 0;
		sum -= price[i];
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin>>n;
	price.resize(n);
	chk.resize(n);
	reduce.resize(n);
	for(int i = 0;i<n;i++) {
		cin>>price[i];
	}
	for(int i = 0;i<n;i++) {
		int k;
		cin>>k;
		for(int j = 0;j<k;j++) {
			int a,b;
			cin>>a>>b;
			reduce[i].push_back(make_pair(a-1,b));
		}
	}
	func(0);
	cout<<res;
	return 0;
}
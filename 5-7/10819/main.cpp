#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int n;
int arr[20];
vector<int> v,res;
int ans = 0;

void func(int p,int cnt) {
    res.push_back(v[p-1]);
    if(cnt == 1){
        for(int i = 0;i<res.size();i++) {
			int sum = 0;
			for(int i = 0;i<n-1;i++) {
				sum += abs(res[i]-res[i+1]);
			}
			if(sum > ans) {
				ans = sum;
			}
		}
    }
    if(arr[p] == true) {
        return;
    }
    arr[p] = true;
    for(int i = 1;i<=n;i++) {
        if(!arr[i]) {
            func(i,cnt-1);
            arr[i] = false;
        }
    }
    arr[p] = false;
    res.pop_back();
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin>>n;
	v.resize(n);
	for(int i = 0;i<n;i++) {
		cin>>v[i];
	}
    for(int i = 1;i<=n;i++) {
        for(int j = 1;j<10;j++){
            arr[j] = false;
        }
        func(i,n);
    }
	cout<<ans;
	return 0;
}
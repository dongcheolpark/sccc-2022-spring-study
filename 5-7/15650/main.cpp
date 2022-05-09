#include <iostream>
#include <vector>
#include <algorithm>

#define N 9

using namespace std;

bool arr[N];
vector<int> res;
int n,m;

void func(int p,int cnt) {
    res.push_back(p);
    if(cnt == 1){
        for(int i = 0;i<res.size();i++) {
            printf("%d ",res[i]);
        }
        printf("\n");
        res.pop_back();
        return;
    }
    if(arr[p] == true) {
        return;
    }
    arr[p] = true;
    for(int i = p+1;i<=n;i++) {
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
	cin>>n>>m;
    for(int i = 1;i<=n;i++) {
        for(int j = 1;j<N;j++){
            arr[j] = false;
        }
        func(i,m);
    }
}
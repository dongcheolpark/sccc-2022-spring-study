#include <iostream>

using namespace std;

int n,r,c;

int func(int num,int x,int y) {
	if(num<= 1) {
		return r%2*2 + c%2;
	}
	for(int i = 0;i<=1;i++) {
        for(int j = 0;j<=1;j++) {
            if(x+num*i <= r && r<x+num*(i+1) && y+num*j <= c && c<y+num*(j+1) ) {
                int res = num*num*i*2 + num*num*j; 
                return res + func(num/2,x+num*i,y+num*j);
            }
        }
    }
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin>>n>>r>>c;
	cout<<func(2<<(n-1),0,0);
	return 0;
}
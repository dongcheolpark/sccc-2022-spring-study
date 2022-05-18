#include <iostream>

using namespace std;

int n;
bool arr[3000][3000];

void func2(int x,int y, int a) {
    for(int i = x;i<x+a;i++) {
        for(int j = y;j<y+a;j++) {
            arr[i][j] = false;
        }
    }

}

void func(int x,int y,int a) {
	if(a == 3) {
		for(int i = x;i<x+3;i++) {
			for(int j = y;j<y+3;j++) {
				if(i == x+1&& j == y+1) arr[i][j] = 0;
				else arr[i][j] = 1;
			}
		}
		return;
	}
	for(int i = x;i<x+a;i+=a/3){
        for(int j = y;j<y+a;j+=a/3) {
           if(!(i == x+a/3&&j == y+a/3)) func(i,j,a/3);
        }
    }
}

int main() {
	cin>>n;
	for(int i = 1;i<=n;i++) {
		for(int j = 1;j<=n;j++) {
			arr[i][j] = 0;
		}
	}
	func(1,1,n);
	for(int i = 1;i<=n;i++) {
		for(int j = 1;j<=n;j++) {
			cout<<(arr[i][j] ? '*' :' ');
		}
		cout<<'\n';
	}
}
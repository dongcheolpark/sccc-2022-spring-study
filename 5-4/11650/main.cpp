#include <iostream>
#include <vector>

using namespace std;

class point
{
public:
	int x;
	int y;
	point() {}
	point(int x,int y) : x(x),y(y)  {}
	bool operator<(point p) const{
		if(this->x < p.x) {
			return true;
		}
		else if(this->x == p.x) {
			return this->y < p.y;
		} 
		else return false;
	}
};


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin>>n;
	vector<point> v;
	for(int i = 0;i<n;i++) {
		int a,b;
		cin>>a>>b;
		v.push_back(point(a,b));
	}
	sort(v.begin(),v.end());
	for(int i = 0;i<n;i++) {
		cout<<v[i].x<<" "<<v[i].y<<'\n';
	}
}
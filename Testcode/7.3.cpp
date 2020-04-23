#include<bits/stdc++.h>
using namespace std;

class Base {
public:
	int p;
};

class Left : virtual public Base {
public:
	int l;
	Left(int l) : l(l) {}
};

class Right : virtual public Base {
public:
	int r;
	Right(int r) : r(r) {}
};

class Merge : virtual public Left, virtual public Right {
public:
	int m;
	Merge(int m,int l,int r,int p) : Left(l),Right(r),m(m) {
		cout<<"Con"<<endl;
	}
	~Merge() {
		cout<<"Des"<<endl;
	}
	void show() {
		cout<<m<<" "<<l<<" "<<r<<" "<<p<<endl;
	}
};

int main()
{
	Merge me(1,2,3,4);
	me.show();
	return 0;
} 

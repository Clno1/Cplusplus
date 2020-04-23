#include<bits/stdc++.h>
using namespace std;

class test
{
private:
	int t;
public:
	test(int tt) : t(tt) {
	}
	~test() {
		cout<<"OO"<<endl;
	}
	
	int gett() {return t;}
};

int main()
{
	test t(10);
	cout<<t.gett()<<endl;
	
	test *tt=new test(100);
	cout<<tt->gett()<<endl;
	return 0;
}

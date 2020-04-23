#include<bits/stdc++.h>
using namespace std;

class BaseClass {
public:
	int Number;
	int getNumber() { return Number; }
	//
	BaseClass() { cout<<"Base Construct"<<endl; }
	~BaseClass() { cout<<"Base Destruct"<<endl; }
};

class DerivedClass : BaseClass {
public:
	DerivedClass() {
		Number=0;
		Number++;
		cout<<"De Con"<<endl;
	}
	~DerivedClass() {
		Number--;
		cout<<"De Dec"<<endl;
	}
};

int main()
{
	DerivedClass dd;
	DerivedClass d();
	return 0;
}

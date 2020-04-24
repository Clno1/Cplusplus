#include<bits/stdc++.h>
using namespace std;

//自己实现的异常类 
class CException {
public:
	CException() {}
	virtual ~CException() {}
	void Reason() {
		cout<<"CEx"<<endl;
	}
};

//要运行的函数 
void fn1() {
	throw CException();
}

int main()
{
	try {
		fn1();
	} catch(CException& ce) {	//捕捉到fn1抛出的异常 
		ce.Reason();
	}
	return 0;
} 

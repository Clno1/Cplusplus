#include<bits/stdc++.h>
using namespace std;

//�Լ�ʵ�ֵ��쳣�� 
class CException {
public:
	CException() {}
	virtual ~CException() {}
	void Reason() {
		cout<<"CEx"<<endl;
	}
};

//Ҫ���еĺ��� 
void fn1() {
	throw CException();
}

int main()
{
	try {
		fn1();
	} catch(CException& ce) {	//��׽��fn1�׳����쳣 
		ce.Reason();
	}
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;

class Fraction {
private:
	int numerator=0;	//���� 
	int denominator=1;	//fenmu
public:
	Fraction(int n,int d) : numerator(n),denominator(d) {
	}
	friend ostream& operator << (ostream& os,const Fraction& f) {
		os<<f.numerator<<"/"<<f.denominator;
		return os;
	}
};

void get_unique_ptr(const unique_ptr<Fraction>& f) {
	cout<<*f<<endl;
}
void get_unique_ptr2(unique_ptr<Fraction>& f) {
	cout<<*f<<endl;
}

void test_unique_ptr() {
	//newһ����������f1ָ���� 
	unique_ptr<Fraction> f1{new Fraction(3,5)};
	cout<<*f1<<endl;
	
	//��move�ƽ�����Ȩ 
	unique_ptr<Fraction> f2;
	f2=move(f1);
	cout<<(f1==nullptr)<<endl;		//��ʱf1����Ȩ�ƽ�����Ϊ��ָ�� 
	cout<<*f2<<endl;	//f2���f1�Ŀ��� 
	
	//C++14,��make_uniqueֱ�Ӵ���ָ�룬�������������ȴ������ 
	auto f3=make_unique<Fraction>(2,7);
	cout<<*f3<<endl;
	
	get_unique_ptr(f3);		//uniqueָ����Դ��ݸ���ֵ�������ã����ı�����Ȩ 
	get_unique_ptr2(f3);	//�ǳ���Ҳ���ԣ��ƶ����� 
	
//	//�������飬���Ǿ�����������������Ϊ�������std::array����std::vector
//	auto f4=make_unique<Fraction[]>(4);
//	cout<<f4[0]<<endl;
}

void test_shared_ptr() {
	//Ҳ��make_shared�������sharedָ�� 
	auto ptr1=make_shared<Fraction>(1,4);
	cout<<*ptr1<<endl;
	cout<<ptr1.use_count()<<endl;
	//��ֵ����ʹ����ǰ��ָ��ʧȥ����Ȩ 
	{
		auto ptr2=ptr1;
		cout<<(ptr1==nullptr)<<endl;
		cout<<*ptr2<<endl;
		//use_count���Է��ض���������� 
		cout<<ptr1.use_count()<<"  "<<ptr2.use_count()<<endl;
	}
	//ptr2��3�������ˣ�����������Ӧ�ü�һ 
	cout<<ptr1.use_count()<<endl;
}

void test_weak_ptr() {
	auto ptr1=make_shared<Fraction>(3,6);
	cout<<*ptr1<<" "<<ptr1.use_count()<<endl;
	//����һ��weak_ptr�ܹ����Զ�����������Ӱ�� 
	weak_ptr<Fraction> ptr2=ptr1;
	cout<<*(ptr2.lock())<<endl;	//ͨ��lock()��������һ��shared_ptr���� 
	cout<<ptr1.use_count()<<" "<<ptr2.use_count()<<endl;
}

int main()
{
	//test_unique_ptr();
	//test_shared_ptr();
	test_weak_ptr(); 
	return 0;
} 

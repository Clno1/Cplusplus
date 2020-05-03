#include<bits/stdc++.h>
using namespace std;

class Fraction {
private:
	int numerator=0;	//分子 
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
	//new一个对象并且用f1指向它 
	unique_ptr<Fraction> f1{new Fraction(3,5)};
	cout<<*f1<<endl;
	
	//用move移交控制权 
	unique_ptr<Fraction> f2;
	f2=move(f1);
	cout<<(f1==nullptr)<<endl;		//此时f1控制权移交，变为空指针 
	cout<<*f2<<endl;	//f2获得f1的控制 
	
	//C++14,用make_unique直接创造指针，而不用像上面先创造对象 
	auto f3=make_unique<Fraction>(2,7);
	cout<<*f3<<endl;
	
	get_unique_ptr(f3);		//unique指针可以传递给左值常量引用，不改变所有权 
	get_unique_ptr2(f3);	//非常量也可以，移动语义 
	
//	//处理数组，但是尽量不用这样做，因为你可以用std::array或者std::vector
//	auto f4=make_unique<Fraction[]>(4);
//	cout<<f4[0]<<endl;
}

void test_shared_ptr() {
	//也是make_shared方法获得shared指针 
	auto ptr1=make_shared<Fraction>(1,4);
	cout<<*ptr1<<endl;
	cout<<ptr1.use_count()<<endl;
	//赋值不会使得以前的指针失去所有权 
	{
		auto ptr2=ptr1;
		cout<<(ptr1==nullptr)<<endl;
		cout<<*ptr2<<endl;
		//use_count可以返回对象的引用数 
		cout<<ptr1.use_count()<<"  "<<ptr2.use_count()<<endl;
	}
	//ptr2和3被析构了，对象引用数应该减一 
	cout<<ptr1.use_count()<<endl;
}

void test_weak_ptr() {
	auto ptr1=make_shared<Fraction>(3,6);
	cout<<*ptr1<<" "<<ptr1.use_count()<<endl;
	//构造一个weak_ptr能够不对对象的引用造成影响 
	weak_ptr<Fraction> ptr2=ptr1;
	cout<<*(ptr2.lock())<<endl;	//通过lock()方法返回一个shared_ptr对象 
	cout<<ptr1.use_count()<<" "<<ptr2.use_count()<<endl;
}

int main()
{
	//test_unique_ptr();
	//test_shared_ptr();
	test_weak_ptr(); 
	return 0;
} 

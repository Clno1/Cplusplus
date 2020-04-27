#include<bits/stdc++.h>
using namespace std;

class Complex {
public:
	double real;
	double image;
	Complex(double r=2.0,double i=-2.0);
	Complex(const Complex& c);
	
	//一元运算符推荐不用友元 
	Complex& operator += (const Complex& c);
	Complex& operator -= (const Complex& c);
	
	//二元运算符推荐用友元 
	friend bool operator == (const Complex& c1,const Complex& c2);
	friend Complex operator + (const Complex& c1,const Complex& c2);
	friend ostream& operator << (ostream& o,const Complex& c);
};

Complex::Complex(double r,double i) : real(r),image(i) { }
Complex::Complex(const Complex& c) {
	this->real=c.real;
	this->image=c.image;
}

Complex& Complex::operator +=(const Complex& c) {
	this->real+=c.real;
	this->image+=c.image;
	return *this;
}

Complex& Complex::operator -=(const Complex& c) {
	this->real-=c.real;
	this->image-=c.image;
	return *this;
}

bool operator == (const Complex& c1,const Complex& c2) {
	return (c1.real==c2.real && c1.image==c2.image);
}

Complex operator + (const Complex& c1,const Complex &c2) {
	Complex ret(c1.real+c2.real,c1.image+c2.image);
	return ret;
}

ostream& operator << (ostream& o,const Complex& c) {
	o<<c.real<<" "<<c.image<<endl;
	return o; 
}

int main()
{
	Complex c1;
	Complex c2(3.0,-3.0);
	Complex c3=c1;
	cout<<"c1:"<<c1<<"c2:"<<c2<<"c3:"<<c3;
	cout<<"c1==c2 ? "<<(c1==c2)<<endl;
	cout<<"c1==c3 ? "<<(c1==c3)<<endl;
	cout<<"c1+c2 : "<<(c1+c2);
	
	c1+=c2;
	cout<<"c1:"<<c1;
	c1-=c3;
	cout<<"c1:"<<c1;
	return 0;
} 

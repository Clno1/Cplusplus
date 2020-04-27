#include<bits/stdc++.h>
#include <cstdlib>
using namespace std;

//重载运算符实验程序 
class Point {
private:
	int _x,_y;
	
public:
	Point(int x=0,int y=0) : _x(x),_y(y) {}
	Point& operator ++ ();	// ++i  因为返回的值还要做运算，所以返回引用 
	Point operator ++ (int);	// i++  返回的就是之前的副本，不需要返回引用 
	Point& operator -- ();	//--i    
	Point operator -- (int);	//i-- 
	//注意是友元函数，重载输出插入符，要返回输出流对象继续操作 
	friend ostream& operator << (ostream& o,Point& p); 
};

//返回对象引用 ,所以可以这样用 ： ++i=3 
Point& Point::operator ++ () {
	_x++;
	_y++;
	return *this; 
}

//i++
Point Point::operator ++(int) {
	Point temp=*this;
	++ *this; 	 //调用前自增使得自己自增 
	return temp;	//但是返回的是副本 
} 

Point& Point::operator --() {
	_x--;
	_y--;
	return *this;
} 

Point Point::operator --(int) {
	Point temp=*this;
	-- *this;
	return temp;
} 

//友元函数：重载输出插入符
ostream& operator << (ostream& o,Point& p) {
	o<<'('<<p._x<<','<<p._y<<')';
	return o;
}

int main()
{
	Point p(1,2);
	cout<<p<<endl;  p++; 
	cout<<(p++)<<endl;
//	cout<<(p++)<<endl;
//	cout<<++p<<endl;
//	cout<<p--<<endl;
//	cout<<--p<<endl;
	return 0;
}

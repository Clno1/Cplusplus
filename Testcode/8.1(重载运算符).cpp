#include<bits/stdc++.h>
#include <cstdlib>
using namespace std;

//���������ʵ����� 
class Point {
private:
	int _x,_y;
	
public:
	Point(int x=0,int y=0) : _x(x),_y(y) {}
	Point& operator ++ ();	// ++i  ��Ϊ���ص�ֵ��Ҫ�����㣬���Է������� 
	Point operator ++ (int);	// i++  ���صľ���֮ǰ�ĸ���������Ҫ�������� 
	Point& operator -- ();	//--i    
	Point operator -- (int);	//i-- 
	//ע������Ԫ��������������������Ҫ�������������������� 
	friend ostream& operator << (ostream& o,Point& p); 
};

//���ض������� ,���Կ��������� �� ++i=3 
Point& Point::operator ++ () {
	_x++;
	_y++;
	return *this; 
}

//i++
Point Point::operator ++(int) {
	Point temp=*this;
	++ *this; 	 //����ǰ����ʹ���Լ����� 
	return temp;	//���Ƿ��ص��Ǹ��� 
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

//��Ԫ������������������
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

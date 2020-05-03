#include<bits/stdc++.h>
using namespace std;

//这样是类型模板，类型参数表示的是一种类型而非值 
template <typename T>
int compare(const T& a,const T& b) {
	if (a<b) return -1;
	if (a>b) return 1;
	return 0;
} 

//这样是非类型参数，表示一个值而非一个类型
//提供一个常量表达式，编译器在编译时实例化模板 
template<unsigned N,unsigned M>		
int compare2(const char (&p1)[N],const char (&p2)[M]) {
	return strcmp(p1,p2);
} 
 

int main()
{
	cout<<compare(1,2)<<endl;
	cout<<compare("1651","1561")<<endl;
	cout<<compare(9,3)<<endl;
	cout<<compare(1.2232,0.2125)<<endl;
	
	//这个"321"和"32"长度不同是不能调用compare的，长度不同数组视为不同类型 
	//cout<<compare("321","32")<<endl;
	cout<<compare2("32","321")<<endl;
	return 0;
}
